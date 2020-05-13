PROJECT=coldet
LIB=libcoldet.a
LIBPATH=.
CC=g++
OPT=-O2
CFLAGS=-c $(OPT) -DGCC

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

KOS_CFLAGS += -I/home/john/formation/Dreamcast/STL/STLport-4.6/stlport -O2

$(LIB): $(OBJS)
	rm -f $(LIB)
	$(KOS_AR) rcs $(LIBPATH)/$(LIB) $(OBJS)

clean:
	rm *.o $(LIB)

include $(KOS_BASE)/Makefile.rules
