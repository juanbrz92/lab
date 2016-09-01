GETS= contador
FLAGS= -Wall -g
CC= gcc
TARGETS= contador
COLA= -pthread

contador: contar.h mostar.h main.c contar.c mostrar.c
	$(CC) $(FLAGS) -o $@ $^ $(COLA)

clean:
	rm -fv $(TARGETS) *.o*~
