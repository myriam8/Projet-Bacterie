all: bacterie.o conditions.o nourriture.o E_coli.o main.o main


bacterie.o: bacterie.cpp bacterie.hh conditions.hh nourriture.hh 
	g++ -g -c bacterie.cpp

E_coli.o: E_coli.cpp E_coli.hh bacterie.hh
	g++ -g -c E_coli.cpp `pkg-config --cflags opencv4` `pkg-config --libs opencv4`

conditions.o: conditions.cpp conditions.hh 
	g++ -g -c  conditions.cpp 

nourriture.o: nourriture.cpp nourriture.hh
	g++ -g -c nourriture.cpp

main.o: main.cpp nourriture.hh conditions.hh bacterie.hh
	g++ -g -c  main.cpp `pkg-config --cflags opencv4` `pkg-config --libs opencv4`

main: bacterie.o conditions.o nourriture.o E_coli.o main.o
	g++ -o main bacterie.o conditions.o nourriture.o E_coli.o main.o `pkg-config --cflags opencv4` `pkg-config --libs opencv4`

clean:
	rm -f *.o
	


