MAINFILE=main.cpp
FLAGS=-std=c++11 -Wall -o
EXENAME=main

TELEPHONEOBJECT=Telephone.o
TELEPHONECLASS=Telephone.cpp
TELEPHONEHEADER=Telephone.h

main: $(TELEPHONEOBJECT)
	g++ $(MAINFILE) $(FLAGS) $(EXENAME) $(TELEPHONEOBJECT)

$(TELEPHONEOBJECT): $(TELEPHONEHEADER) $(TELEPHONECLASS)
	g++ -c -std=c++11 -Wall $(TELEPHONECLASS)

clean:
	$(RM)
