.PHONY: all install uninstall clean

all: vcsk

vcsk:
	mkdir -p build
	cd build && cmake .. && make
	mv build/vcsk .

install: vcsk
	mv vcsk /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/vcsk

clean:
	rm -f vcsk
	rm -rf build/*
	touch build/.gitkeep
