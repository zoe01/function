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
		"a={} b={}"
		"i=0"
		"for x=0,20,2 do"
		"y=x*x"
		"a[i]=x b[i]=y"
		"print(a[i],b[i])"
		"i=i+1"
		"end";

	//char fun[100];
	//printf("Input the function:");
	//scanf("%s", fun);
	//double x1, x2;
	//printf("Input the range of x:");
	//scanf("%lf %lf",&x1,&x2);
	//float step;
	//printf("Input the step of x:");
	//scanf("%f", &step);
	//
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_base(L);             /* opens the basic library */
	luaopen_table(L);            /* opens the table library */
	luaopen_io(L);               /* opens the I/O library */
	luaopen_string(L);           /* opens the string lib. */
	luaopen_math(L);             /* opens the math lib. */

	////把一个数据送给Lua
	//lua_pushstring(L, fun);
	//lua_setglobal(L, "f(x)");
	//lua_pushnumber(L, x1);
	//lua_setglobal(L, "x1");
	//lua_pushnumber(L, x2);
	//lua_setglobal(L, "x2");
	//lua_pushnumber(L, step);
	//lua_setglobal(L, "step");

	//执行
	int error;
	//while (fgets(buff, sizeof(buff), stdin) != NULL) {
		//sprintf_s(buf, 256, "print ( %s)", buff, 256);
		error = luaL_loadbuffer(L, lua1, strlen(lua1), "line") ||
			lua_pcall(L, 0, 0, 0);
		if (error) {
			fprintf(stderr, "%s", lua_tostring(L, -1));
			lua_pop(L, 1);  /* pop error message from the stack */

		}

	//}

	lua_close(L);
	return 0;
}