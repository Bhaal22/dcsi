TARGET = dcsi.elf
OBJS = romdisk.o  Element.o \
	assets/PalmTree.o  \
	assets/TheLittleHouseOnThePrairie.o \
	assets/StartPane.o \
	Camera.o \
	Vehicle.o Landscape.o GraphicalElement.o \
	assets/SkyBox.o BoundingBox.o \
	assets/OisisVehicle.o \
	Init.o Main.o \
	io/ogg.o \
	menu/Menu2D.o \
	io/wav.o \
	assets/Caisse.o \
	assets/MomoVehicle.o \
	assets/NoelVehicle.o \
	game.o \
	menu/MenuManager.o \
#video.o
#KOS_CFLAGS +=	-DDREAMCAST -I/net/home/m/muller/bin/STLport-4.6/stlport  -I/net/home/m/muller/kos/addons/libjpeg

KOS_CFLAGS += -I. -I../lib/coldet -DDREAMCAST -I$(KOS_BASE)/../kos-ports/ -I../../Libvfdc/include/
KOS_LDFLAGS += -L../lib/coldet -L../../Libvfdc/lib/

#-I/home/john/formation/Dreamcast/STL/STLport-4.6/stlport -DDREAMCAST 

all: rm-elf $(TARGET)

include ${KOS_BASE}/Makefile.rules

rm-elf:
	-rm -f $(TARGET)
	-rm -f romdisk.o romdisk.img

clean: rm-elf
	-rm -f $(OBJS)
	rm *~ -f

#$(TARGET): $(OBJS)
#	$(KOS_CC)  $(KOS_CFLAGS) $(KOS_LDFLAGS) -o $(TARGET) $(KOS_START) \
#		$(OBJS) $(DATAOBJS) $(OBJEXTRA) -L$(KOS_BASE) -lkglx -lk++ -lpng -lpcx -ljpeg -lz -lm $(KOS_LIBS)

#-lk++
#-lmpg
$(TARGET): $(OBJS)
	kos-c++ -Wall -o $(TARGET) $(OBJS) -lkglx -loggvorbisplay -lvorbis -logg -lcoldet -ljpeg -lpng -lpcx -lz -ldcplib -lm -lkosutils

#-lk++ -lpng -lpcx -ljpeg -lz -lkmg  -lm -lcoldet 

romdisk.img:
	$(KOS_GENROMFS) -f romdisk.img -d ../data/romdisk -v

romdisk.o: romdisk.img
	$(KOS_BASE)/utils/bin2o/bin2o romdisk.img romdisk romdisk.o

run: 
	$(KOS_LOADER) $(TARGET)

dist:
	rm -f $(OBJS) romdisk.o romdisk.img
	$(KOS_STRIP) $(TARGET)

