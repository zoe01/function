#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <string.h>

int main(void) {
	char buff[256];
	char buf[256];
	int error;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_base(L);             /* opens the basic library */
	luaopen_table(L);            /* opens the table library */
	luaopen_io(L);               /* opens the I/O library */
	luaopen_string(L);           /* opens the string lib. */
	luaopen_math(L);             /* opens the math lib. */
	char s1[] = "lzkx";
	char s2 = "zny";
	printf("input: ddd\n");
	sacnf_s();
	while (fgets(buff, sizeof(buff), stdin) != NULL) {
  		sprintf_s(buf,256, "print ( %s)", buff,256);
		error = luaL_loadbuffer(L, buf, strlen(buf), "line") ||
			lua_pcall(L, 0, 0, 0);
		if (error) {
			fprintf(stderr, "%s", lua_tostring(L, -1));
			lua_pop(L, 1);  /* pop error message from the stack */
			
		}

	}

	lua_close(L);
	return 0;

}