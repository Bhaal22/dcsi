.PHONE: all

PROJECT=DCSI
TARGET = dcsi.elf
STRIP = dcsi.bin
CDI=dcsi.cdi
ISO=dcsi.iso
BURN_FOLDER=burn
SCRAMBLE=1ST_READ.BIN
IP=resources/IP.BIN

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
	menu/FontRenderer.o \
	menu/MenuItem.o \
	menu/MenuManager.o \
#video.o

KOS_CFLAGS += -I. -I../libs/coldet -DDREAMCAST -I$(KOS_BASE)/../kos-ports/ -I../../Libvfdc/include/ -Wno-unused-function
KOS_LDFLAGS += -L../libs/coldet -L../../Libvfdc/lib/

all: clean rm-elf $(TARGET)

include ${KOS_BASE}/Makefile.rules
include ${EXTRA_MAKEFILE_BASE}/Makefile.burn.rules

rm-elf:
	rm -f $(TARGET)
	rm -f romdisk.o romdisk.img

clean: rm-elf
	rm -f $(OBJS)
	rm *~ -f

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

