GETS= servidor
FLAGS= -Wall -g
CC= gcc
TARGETS= servidor

servidor: servidor.c extencion.c respuesta.c nombre.c errores.c hora.c longitud.c extencion.h respuesta.h nombre.h errores.h hora.h longitud.h
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm -fv $(TARGETS) *.o*~
