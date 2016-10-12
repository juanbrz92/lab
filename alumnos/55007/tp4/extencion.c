#include "extencion.h"

int extencion(char* buffer,int leido){
	char copia[leido],*cadena;
	int opcion,len,i;
        strcpy(copia,buffer);
        cadena = strtok(copia,"/");
        cadena = strtok(NULL,".");
        cadena = strtok(NULL," ");
        len=strlen(cadena);
        char cad[len];
        for(i=0;i<len;i++){
            cad[i]=cadena[i];
        }
        if(strcmp(cad,"txt")==0){
             printf("peticion: txt\n");
             opcion=1;
        }else if(strcmp(cad,"html")==0){
             printf("peticion: html\n");
             opcion=2;
        }else if(strcmp(cad,"pdf")==0){
             printf("peticion: pdf\n");
             opcion=3;
        }else if(strcmp(cad,"jpg")==0){
             printf("peticion: jpg\n");
             opcion=4;
        }else{
	     printf("Archivo no valido\n");
	     opcion=5;
	}
return opcion;
}
