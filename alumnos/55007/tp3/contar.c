#include "contar.h"

int *contar(char* buffer,int leido){
	
	int *dist,i,palabras=0,caracter=0;
	dist=calloc(1,20);
	for(i=0;i<20;i++){//memset()
		dist[i]=0;
	}
	for(i=0;i<leido;i++){
		if(buffer[i]==' ' || i==leido-1){
			palabras++;
			dist[caracter]=dist[caracter]+1;
			caracter=0;
		}else{
			caracter++;
		}
	}
return dist;
}
