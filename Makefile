CC := "g++"
version := "-std=c++23"
invoke := $(CC) $(version)
alltargets := main

all: $(alltargets) cleanouts
	./main

main: main.cpp
	$(invoke) -g main.cpp -o main
	echo "Compiled main"

cleanouts:
	rm -f *.out
	echo "Cleaned outfiles"

clean:
	rm -f *.out
	rm -f $(alltargets)