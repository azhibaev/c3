# Please set dir for temp header files
HEADERS_DIR=include

INCLUDE=-I . -I common -I module -I file -I char_string -I parse -I utopia -I $(HEADERS_DIR) -I prime -I chars
CFLAGS=-Wall -g -D_DEBUG ${INCLUDE}
LDLIBS=-lm
MOD_H=$(shell find $(SOURCEDIR) -name '*.mod.h')
OBJECTS_H=$(MOD_H:%.mod.h=%.h)

# Uncomment next string (remove '#') after mod_to_h compile
#include $(OBJECTS_H)

%.h: %.mod.h
	test/mod_to_h $^ $(HEADERS_DIR)/

