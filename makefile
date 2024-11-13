CC := "g++"
version := "-std=c++23"
invoke := $(CC) $(version)
allobj := src/obj/calendar.o src/obj/director.o src/obj/events.o src/obj/ledger.o src/obj/regions.o

all: main
	@echo "make: command make run to execute"

run: main
	@echo "make: Executing main"
	./main
	@echo "make: Main executed"

src/obj/calendar.o: src/cpp/calendar.cpp
	@echo "make: compiling calendar.o..."
	$(invoke) -c src/cpp/calendar.cpp -o src/obj/calendar.o
	@echo "make: compiled calendar.cpp to calendar.o"

src/obj/director.o: src/cpp/director.cpp
	@echo "make: compiling director.o..."
	$(invoke) -c src/cpp/director.cpp -o src/obj/director.o
	@echo "make: compiled director.cpp to director.o"

src/obj/events.o: src/cpp/events.cpp
	@echo "make: compiling events.o..."
	$(invoke) -c src/cpp/events.cpp -o src/obj/events.o
	@echo "make: compiled events.cpp to events.o"

src/obj/ledger.o: src/cpp/ledger.cpp
	@echo "make: compiling ledger.o..."
	$(invoke) -c src/cpp/ledger.cpp -o src/obj/ledger.o
	@echo "make: compiled ledger.cpp to ledger.o"

src/obj/regions.o: src/cpp/regions.cpp
	@echo "make: compiling regions.o..."
	$(invoke) -c src/cpp/regions.cpp -o src/obj/regions.o
	@echo "make: compiled regions.cpp to regions.o"

main: src/cpp/main.cpp $(allobj)
	@echo "make: compiling main..."
	$(invoke) src/cpp/main.cpp -o main $(allobj)
	@echo "make: compiled and linked main.cpp with object files to main"

clean:
	@echo "make: Cleaning object files and main output"
	rm -f $(wildcard src/obj/*.o)
	rm -f main
	@echo "make: Directories cleaned"