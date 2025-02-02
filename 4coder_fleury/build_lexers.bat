@echo off

call ..\bin\build_one_time .\4coder_fleury_odin_lexer_gen.cpp ..\..\
..\..\one_time.exe
copy ..\generated\lexer_odin.h .\generated\4coder_fleury_lexer_odin.h
copy ..\generated\lexer_odin.cpp .\generated\4coder_fleury_lexer_odin.cpp


call ..\bin\build_one_time .\4coder_fleury_zig_lexer_gen.cpp ..\..\
..\..\one_time.exe
copy ..\generated\lexer_zig.h .\generated\4coder_fleury_lexer_zig.h
copy ..\generated\lexer_zig.cpp .\generated\4coder_fleury_lexer_zig.cpp


call ..\bin\build_one_time .\4coder_fleury_rust_lexer_gen.cpp ..\..\
..\..\one_time.exe
copy ..\generated\lexer_rust.h .\generated\4coder_fleury_lexer_rust.h
copy ..\generated\lexer_rust.cpp .\generated\4coder_fleury_lexer_rust.cpp


call ..\bin\build_one_time .\4coder_fleury_jai_lexer_gen.cpp ..\..\
..\..\one_time.exe
copy ..\generated\lexer_jai.h .\generated\4coder_fleury_lexer_jai.h
copy ..\generated\lexer_jai.cpp .\generated\4coder_fleury_lexer_jai.cpp
