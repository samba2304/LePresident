CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
LDLIBS=-lm
RM=rm -f
OBJ=carte.o joeur.o LePresident.o
EXE=LePresident
#Pour produire le fichier exécutable
$(EXE):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
#Pour produire les fichiers objets
LePresident.o:LePresident.c joeur.h carte.h 
	$(CC) $(CFLAGS) -c LePresident.c
carte.o:carte.c carte.h 
	$(CC) $(CFLAGS) -c carte.c
joeur.o:joeur.c joeur.h
	$(CC) $(CFLAGS) -c joeur.c
#Pour effacer les objets et les exécutables
clean:
	$(RM) $(OBJ) $(EXE)