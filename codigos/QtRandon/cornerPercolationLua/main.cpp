#include <QtGui/QApplication>
#include "mainwindow.h"

#include <lua5.1/lua.hpp>

lua_State *L;

static void loadfile(lua_State *L, const char* fname)
{
    if (luaL_dofile(L,fname)!=0) {
        fprintf(stderr,"%s: %s\n","myprog",lua_tostring(L,-1));
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    L=lua_open();
    luaL_openlibs(L);
    loadfile(L,"init.lua");
    loadfile(L,"rule.lua");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
