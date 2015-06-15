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
	double x;
	double y;
}point;
int findsub(char *a, char *b)
{
	int i, j, k;
	for (i = 0; a[i] != '\0'; i++){
		for (j = i, k = 0; a[j] == b[k] && k < strlen(b); j++, k++);
		if (b[k] == '\0')
			return i;
	}
	return -1;
}
int replace_str(char *array, char *t, char *g)
{
	int fs, lt = strlen(t), lg = strlen(g);
	char temps[100];
	if (strlen(array) == 0)
		return 0;
	fs = findsub(array, t);
	if (fs == -1)
		return 0;
	else{
		strcpy(temps, array + fs + lt);
		array[fs] = '\0';
		strcat(array, g);
		strcat(array, temps);
		return 1 + replace_str(array + lg + fs, t, g);
	}
}
void TranFunction(char *fun)
{
	//数学函数库
	replace_str(fun, "pi", "math.pi");
	replace_str(fun, "abs", "math.abs");
	replace_str(fun, "ceil", "math.ceil"); //向上取整
	replace_str(fun, "floor", "math.floor"); //向下取整
	replace_str(fun, "max", "math.max");  //取参数最大值 max(1,2,3)=3
	replace_str(fun, "min", "math.min");  //取参数最小值
	replace_str(fun, "pow", "math.pow");   //pow(x,y)=x^y
	replace_str(fun, "sqrt", "math.sqrt");
	replace_str(fun, "mod", "math.mod");  //取模 mod(99.2)=1
	replace_str(fun, "modf", "math.modf"); //取整数和小数部分
	replace_str(fun, "random", "math.random");
	replace_str(fun, "rad", "math.rad");  //角度转弧度
	replace_str(fun, "deg", "math.deg");  //弧度转角度
	replace_str(fun, "exp", "math.exp");
	replace_str(fun, "log", "math.log");  //自然对数
	replace_str(fun, "log10", "math.log10");
	replace_str(fun, "ldexp", "math.ldexp");  //ldexp(x.y)=x*(2^y)
	replace_str(fun, "sin", "math.sin");
	replace_str(fun, "cos", "math.cos");
	replace_str(fun, "tan", "math.tan");
	replace_str(fun, "asin", "math.asin");
	replace_str(fun, "acos", "math.acos");
	replace_str(fun, "atan", "math.atan");
}
point* analyzeFunction()
//int main()
{
	long size;
	point *dot;
	char *lua1 =
		"a={}\n b={}\n"
		"i=0\n"
		"for x=x1,x2,step do\n";
	//"y=f\n"
	char *lua2 =
		"a[i]=x\n b[i]=y\n"
		"print(a[i],b[i])\n"
		"i=i+1\n"
		"end\n";
	char lua[1000];

	double x1, x2;
	printf("Input the range of x:");
	scanf("%lf %lf", &x1, &x2);

	double step;
	printf("Input the step of x:");
	scanf("%lf", &step);

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

	char fun[256];// = { "y=x*x\n" };

	int error;
	printf("Input the function:");
	fflush(stdin);
	fgets(fun, sizeof(fun), stdin);
	TranFunction(fun);
	sprintf(lua, "%s%s%s", lua1, fun, lua2);
	//执行
	error = luaL_loadbuffer(L, lua, strlen(lua), "line") ||
		lua_pcall(L, 0, 0, 0);
	if (error) {
		fprintf(stderr, "%s", lua_tostring(L, -1));
		lua_pop(L, 1);  /* pop error message from the stack */
	}
	else{
		//从lua中获得坐标数组
		lua_getglobal(L, "a");
		size = luaL_len(L, -1);//相关于#table
		dot = (point *)malloc((size)*sizeof(point)); //
		dot[0].x = dot[0].y = size;         //dot[0].x.y接收点的个数，点坐标从下标1开始记录
		int a = 1;
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
		int b = 1;
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
	lua_close(L);
	return dot;
}