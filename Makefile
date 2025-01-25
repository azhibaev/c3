# Please set dir for temp header files
HEADERS_DIR=include

INCLUDE=-I. -Icommon -Imodule -Ifile -Iparse -Iutopia -I$(HEADERS_DIR) -Iprime -Ichars
CFLAGS=-Wall -g -D_DEBUG ${INCLUDE}
LDLIBS=-lm
MOD_H=$(shell find $(SOURCEDIR) -name '*.mod.h')
OBJECTS_H=$(MOD_H:%.mod.h=%.h)

# Uncomment next string (remove '#') after mod_to_h compile
include $(OBJECTS_H)

%.h: %.mod.h
	mod_to_h/mod_to_h $^ $(HEADERS_DIR)/

