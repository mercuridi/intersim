CC := "g++"
version := "-std=c++23"
invoke := $(CC) $(version)
allobj := src/obj/calendar.o src/obj/director.o src/obj/events.o src/obj/ledger.o src/obj/regions.o

.SILENT: all

all: main run

run: main
	@echo "make: Executing main"
	./main
	@echo "make: Main executed"

src/obj/calendar.o: src/cpp/calendar.cpp
	@echo "make: calendar.o not found in src/obj/, compiling..."
	$(invoke) -c src/cpp/calendar.cpp -o src/obj/calendar.o
	@echo "make: Compiled calendar.cpp to calendar.o"

src/obj/director.o: src/cpp/director.cpp
	@echo "make: director.o not found in src/obj/, compiling..."
	$(invoke) -c src/cpp/director.cpp -o src/obj/director.o
	@echo "make: Compiled director.cpp to director.o"

src/obj/events.o: src/cpp/events.cpp
	@echo "make: events.o not found in src/obj/, compiling..."
	$(invoke) -c src/cpp/events.cpp -o src/obj/events.o
	@echo "make: Compiled events.cpp to events.o"

src/obj/ledger.o: src/cpp/ledger.cpp
	@echo "make: ledger.o not found in src/obj/, compiling..."
	$(invoke) -c src/cpp/ledger.cpp -o src/obj/ledger.o
	@echo "make: Compiled ledger.cpp to ledger.o"

src/obj/regions.o: src/cpp/regions.cpp
	@echo "make: regions.o not found in src/obj/, compiling..."
	$(invoke) -c src/cpp/regions.cpp -o src/obj/regions.o
	@echo "make: Compiled regions.cpp to regions.o"

main: src/cpp/main.cpp $(allobj)
	@echo "make: main not found in base directory, compiling..."
	$(invoke) src/cpp/main.cpp -o main $(allobj)
	@echo "make: Compiled and linked main.cpp with object files to main"

clean:
	@echo "make: Cleaning object files and main output"
	rm -f $(wildcard src/obj/*.o)
	rm -f main
	@echo "make: Directories cleaned"