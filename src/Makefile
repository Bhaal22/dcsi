TARGET = dcsi.elf
OBJS = romdisk.o  Element.o PalmTree.o  \
	TheLittleHouseOnThePrairie.o StartPane.o \
	Camera.o Vehicle.o Landscape.o GraphicalElement.o SkyBox.o BoundingBox.o \
	OisisVehicle.o Init.o Main.o ogg.o Menu2D.o wav.o Caisse.o MomoVehicle.o NoelVehicle.o game.o MenuManager.o video.o
#KOS_CFLAGS +=	-DDREAMCAST -I/net/home/m/muller/bin/STLport-4.6/stlport  -I/net/home/m/muller/kos/addons/libjpeg

KOS_CFLAGS += -I../../coldet -DDREAMCAST -I$(KOS_BASE)/../kos-ports/ -I../../Libvfdc/include/
KOS_LDFLAGS += -L../../coldet -L../../Libvfdc/lib/

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

$(TARGET): $(OBJS)
	kos-c++ -Wall -o $(TARGET) $(OBJS) -lk++ -lmpg -lkglx -loggvorbisplay -lcoldet -ljpeg -lpng -lpcx -lz -ldcplib -lm -lkosutils

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

