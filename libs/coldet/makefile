.PHONY: all

PROJECT=coldet
LIB=libcoldet.a
LIBPATH=.
CC=g++
OPT=-O2
CFLAGS=-c $(OPT) -DGCC -Wno-unused-function

OBJS= \
coldet.o \
coldet_bld.o \
box.o \
box_bld.o \
tritri.o \
math3d.o \
sysdep.o \
mytritri.o

all: $(LIB)

$(LIB): $(OBJS)
	rm -f $(LIB)
	$(KOS_AR) rcs $(LIBPATH)/$(LIB) $(OBJS)

clean:
	rm *.o $(LIB)

include $(KOS_BASE)/Makefile.rules
