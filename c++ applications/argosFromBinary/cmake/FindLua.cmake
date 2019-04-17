set(FIND_LUA_PATHS /usr/local/Cellar/lua/5.3.5_1)

find_path(LUA_INCLUDEDIR lua.h PATH_SUFFIXES lua5.3 PATHS ${FIND_LUA_PATHS}/include)


find_library(LUA_LIBRARY NAMES lua5.3 PATH_SUFFIXES lib PATHS ${FIND_LUA_PATHS})