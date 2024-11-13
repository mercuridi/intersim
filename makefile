CC := "g++"
version := "-std=c++23"
invoke := $(CC) $(version)
alltargets := calendar director events ledger regions

all: main clean

calendar: src/cpp/calendar.cpp
	$(invoke) -c src/cpp/calendar.cpp -o calendar.o
	echo "Compiled calendar"

director: src/cpp/director.cpp
	$(invoke) -c src/cpp/director.cpp -o director.o
	echo "Compiled director"

events: src/cpp/events.cpp
	$(invoke) -c src/cpp/events.cpp -o events.o
	echo "Compiled events"

ledger: src/cpp/ledger.cpp
	$(invoke) -c src/cpp/ledger.cpp -o ledger.o
	echo "Compiled ledger"

regions: src/cpp/regions.cpp
	$(invoke) -c src/cpp/regions.cpp -o regions.o
	echo "Compiled regions"

main: src/cpp/main.cpp $(alltargets)
	$(invoke) src/cpp/main.cpp -o main calendar.o director.o regions.o events.o ledger.o
	echo "Compiled main"

clean:
	rm -f $(wildcard *.o)