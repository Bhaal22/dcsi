.PHONY: all libs

build-docker:
	docker run --rm  -v `pwd`:/src/dcsi -it drylm/dc-dev:1.3 make -C /src/dcsi/src/ libs dcsi

all: libs dcsi 

libs:
	make -C libs/coldet/

dcsi:
	make -C src/
