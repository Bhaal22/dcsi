.PHONY: build

build:
	docker run --rm  -v `pwd`:/src/dcsi -it drylm/dc-dev:1.1 make -C /src/dcsi/src/ 