extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <iostream>
#include <string>
using namespace std;
typedef struct points
{
	long x;
	long y;
}point;
int main()
{
	char *lua1 =
		"a={}\n b={}\n"
		"i=0\n"
		"for x=x1,x2,step do\n";
		//"y=f\n"
	char *lua2=
		"a[i]=x\n b[i]=y\n"
		"print(a[i],b[i])\n"
		"i=i+1\n"
		"end\n";
	char lua[1000];
	char fun[256] = { "y=x*x\n" };

	double x1=0, x2=20;
	//printf("Input the range of x:");
	//scanf("%lf %lf",&x1,&x2);

	float step=1;
	//printf("Input the step of x:");
	//scanf("%f", &step);

	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_base(L);             /* opens the basic library */
	luaopen_table(L);            /* opens the table library */
	luaopen_io(L);               /* opens the I/O library */
	luaopen_string(L);           /* opens the string lib. */
	luaopen_math(L);             /* opens the math lib. */

	////把一个数据送给Lua
	lua_pushnumber(L, x1);
	lua_setglobal(L, "x1");
	lua_pushnumber(L, x2);
	lua_setglobal(L, "x2");
	lua_pushnumber(L, step);
	lua_setglobal(L, "step");

	//执行
	int error;
	//printf("Input the function:"); 
	//fflush(stdin);
	//while (fgets(fun, sizeof(fun), stdin) != NULL) {
		
		sprintf(lua, "%s%s%s", lua1,  fun, lua2);
		error = luaL_loadbuffer(L, lua, strlen(lua), "line") ||
			lua_pcall(L, 0, 0, 0);
		if (error) {
			fprintf(stderr, "%s", lua_tostring(L, -1));
			lua_pop(L, 1);  /* pop error message from the stack */
		}
		else{
			//从lua中获得坐标数组
			point *dot;
			lua_getglobal(L, "a");
			int size = luaL_len(L, -1);//相关于#table
			dot = (point *)malloc((size)*sizeof(long));
			int a = 0;
			for (int i = 1; i <= size; i++)
			{
				lua_pushnumber(L, i);
				lua_gettable(L, -2);
				dot[a].x = lua_tonumber(L, -1);
				a++;
				//这时table[i]的值在栈顶了
				lua_pop(L, 1);//把栈顶的值移出栈，保证栈顶是table以便遍历。
			}
			lua_getglobal(L, "b");
			int b = 0;
			for (int i = 1; i <= size; i++)
			{
				lua_pushnumber(L, i);
				lua_gettable(L, -2);
				dot[b].y = lua_tonumber(L, -1);
				b++;
				//这时table[i]的值在栈顶了
				lua_pop(L, 1);//把栈顶的值移出栈，保证栈顶是table以便遍历。
			}
		}
	//}
	lua_close(L);
	return 0;
}