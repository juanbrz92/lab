#include "errores.h"
#include "respuesta.h"
#include "hora.h"
//fstat
void errores(int fd2,int tipo,char* len){
	 char buffer2[1000];
	 int leido2,hd,hd2;
	 char *fila1="HTTP/1.0 200 OK\n";
         char *fila2="Date: ";
         char *fila3="Content-Type: ";
         char *fila4="Content-Length: ";
         char *tipo1="text/html\n";
         char *tipo2="application/pdf\n";
         char *tipo3="image/jpeg\n";
	 switch(tipo){
	    case 1:
  		  write(fd2,fila1,strlen(fila1));
                  write(fd2,fila2,strlen(fila2));
                  hora(fd2);
                  write(fd2,fila3,strlen(fila3));
                  write(fd2,tipo1,strlen(tipo1));
                  write(fd2,fila4,strlen(fila4));
                  write(fd2,len,strlen(len));
		  write(fd2,"\n\n",2);		 
	    break;
	    case 2:
                  write(fd2,fila1,strlen(fila1));
                  write(fd2,fila2,strlen(fila2));
                  hora(fd2);
                  write(fd2,fila3,strlen(fila3));
                  write(fd2,tipo2,strlen(tipo2));
                  write(fd2,fila4,strlen(fila4));
                  write(fd2,len,strlen(len));
                  write(fd2,"\n\n",2);
            break;
	    case 3:
                  write(fd2,fila1,strlen(fila1));
                  write(fd2,fila2,strlen(fila2));
                  hora(fd2);
                  write(fd2,fila3,strlen(fila3));
                  write(fd2,tipo3,strlen(tipo3));
                  write(fd2,fila4,strlen(fila4));
                  write(fd2,len,strlen(len));
                  write(fd2,"\n\n",2);
            break;
 	    case 404:
        	 hd=open("head.txt",O_RDONLY);
         	 while ((leido2=read(hd,buffer2,sizeof(buffer2)))>0){
                  	write(fd2,buffer2,leido2);
          	 }
          	 close(hd);
	  	 hd2=open("error404.html",O_RDONLY);
          	 while ((leido2=read(hd2,buffer2,sizeof(buffer2)))>0){
               		write(fd2,buffer2,leido2);
         	 }
         	 close(hd2);
	 	 perror("open");		 
            break;
	    case 500:
		 hd=open("head.txt",O_RDONLY);
                 while ((leido2=read(hd,buffer2,sizeof(buffer2)))>0){
                        write(fd2,buffer2,leido2);
                 }
                 close(hd);
                 hd2=open("error500.html",O_RDONLY);
                 while ((leido2=read(hd2,buffer2,sizeof(buffer2)))>0){
                        write(fd2,buffer2,leido2);
                 }
                 close(hd2);		
	    break;
	 }
}
