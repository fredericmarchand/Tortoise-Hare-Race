play:		Hare.o  Mountain.o  Tortoise.o  Hare.o  Snack.o  Screen.o  random.o  Race.o  main.o
		g++ -o play Hare.o Mountain.o Tortoise.o Snack.o Screen.o main.o Race.o random.o -lncurses

main.o:		main.cpp  main.h  Race.h
		g++ -c main.cpp

Race.o:		Race.cpp  Race.h  Tortoise.h  Mountain.h  Hare.h  Snack.h  Screen.h  random.h
		g++ -c Race.cpp

Hare.o:		Hare.cpp  Hare.h  Mountain.h  random.h
		g++ -c Hare.cpp

Tortoise.o:	Tortoise.cpp  Tortoise.h  Mountain.h  random.h
		g++ -c Tortoise.cpp

Mountain.o:	Mountain.cpp  Mountain.h  random.h
		g++ -c Mountain.cpp

Snack.o:	Snack.cpp  Snack.h
		g++ -c Snack.cpp

Screen.o:	Screen.cpp  Screen.h  Tortoise.h  Mountain.h  Hare.h  Snack.h  random.h
		g++ -c Screen.cpp

clean:
	rm -f Tortoise.o Hare.o Mountain.o Snack.o Screen.o Race.o main.o play
