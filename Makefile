.PHONY: depen all install uninstall clean

all: vcsk

vcsk:
	cd build && cmake .. && make
	mv build/vcsk .

depen:
	@echo "Запуск установки зависимостей..."
	@./.install.sh

install: vcsk
	sudo mv vcsk /usr/local/bin/

uninstall: clean
	sudo rm -f /usr/local/bin/vcsk

clean:
	rm -f vcsk
	rm -rf build/*
