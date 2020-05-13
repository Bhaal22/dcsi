.PHONY: all libs

build-docker:
	docker run --rm  -v `pwd`:/src/project -it drylm/dc-dev:1.3

all: libs dcsi 

libs:
	make -C libs/coldet/

dcsi:
	make -C src/

clean: libs-clean dcsi-clean

libs-clean:
	make -C libs/coldet/ clean

dcsi-clean:
	make -C src/ clean

