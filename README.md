# The C³ programming language

A new programming language based on the idea of *simple modules*. This makes it easier for humans to create programs.

## Build

### Video build tutorial

https://github.com/user-attachments/assets/18a59b62-83e0-455c-9bc2-5dd4034914d8

(Optional) Set dir for temp header files in _Makefile_. This dir can be on _tmpfs_ memory disk. This files will update every time when run _make_.

By default, this is the _include_ directory.

Compile the _mod_to_h_ program to get the header files in the _include_ folder from the _*.mod.h_ module files:
```
make test/mod_to_h
```
Uncomment the string in _Makefile_:
```Makefile
include $(OBJECTS_H)
```
Try some example program in _test_ dir:

Test _chars_ string module:
```
make test/string_write
test/string_write
```
Output:
```
56200916c2d0 10240
Hello 48 65 6c 6c 6f 
Hello
buf=56200916c2d0 size=10240 rpos=0 wpos=5 factor=1.500000 
Hello, World ! 48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 20 21 
Hello, World !
buf=56200916c2d0 size=10240 rpos=0 wpos=14 factor=1.500000 
Test 54 65 73 74 
Test
buf=56200916c2d0 size=10240 rpos=0 wpos=4 factor=1.500000 
```

Test _parse_ module:
```
make test/parse_line
test/parse_line
```
Output:
```
test/parse_line
s
"Hello!"
```

Test _prime_ generator module:
```
make test/prime1
test/prime1 10
```
Output:
```
p[0]=0 p[1]=2 p[2]=3 p[3]=5 p[4]=7 p[5]=11 p[6]=13 p[7]=17 p[8]=19 p[9]=23 p[10]=29
```

Test _SHA256_ module:
```
make test/sha256_1
test/sha256_1
```
Output:
```
b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9
```

Example draw graph with OpenGL (old version): [C³ OpenGL](https://github.com/azhibaev/c3_opengl)

Update: https://azhibaev.com/c3.zip
