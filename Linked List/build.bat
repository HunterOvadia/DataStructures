@echo off

IF NOT EXIST build mkdir build
pushd build

set compiler_flags=-nologo -Z7 -MT -Gm- -GR- -EHa- -Od -Oi -WX -W4 -wd4100 -wd4189 -wd4505 -wd4127 

cl %compiler_flags% ../main.c
popd