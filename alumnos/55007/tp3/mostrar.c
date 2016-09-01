#include "mostrar.h"
void mostrar(int *ptr2){
	int i;
	for(i=0;i<20;i++){
        	   if(ptr2[i]!=0){
        	         printf("hay %d palabras con %d caracteres\n ",ptr2[i],i);
        	   }
	}
}

