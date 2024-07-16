cls
cl /c /EHsc main.cpp Database.cpp User.cpp Book.cpp Order.cpp /I C:\sqlite
cl /Fe:main.exe main.obj Database.obj User.obj Book.obj Order.obj /link /LIBPATH:C:\sqlite sqlite3.lib
main.exe