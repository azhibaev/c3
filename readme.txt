1) set dir for temp header files in Makefile
This dir can be on tmpfs memory disk.
This files will update every time when run make.

2) cd mod_to_h
make mod_to_h
cd ..

3) Try some example program in test dir.
make test/string_write
test/string_write

make test/parse_line
test/parse_line

Update: https://azhibaev.com/c3.zip
