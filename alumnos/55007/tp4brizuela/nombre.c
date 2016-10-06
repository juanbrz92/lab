#include "nombre.h"

char* nombre(char* buffer,int leido){
	char copia[leido],*cadena;
        strcpy(copia,buffer);
        cadena = strtok(copia,"/");
	if(buffer[5]==' '){
		return NULL;
	}
        cadena = strtok(NULL," ");
	printf("Nombre del archivo solicitado: %s\n",cadena);
return cadena;
}
