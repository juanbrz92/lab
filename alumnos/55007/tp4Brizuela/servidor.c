#include <stdio.h>
#include <stdlib.h>          
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "extencion.h"
#include "respuesta.h"
#include "nombre.h"
#include "errores.h"
#include "hora.h" 
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <signal.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
   int fd, fd2,val=1,puerto;
   char buffer[1000],option;
   struct sockaddr_in server; 
   struct sockaddr_in client; 
	
	
   while ((option = getopt(argc, argv,"-p:")) != -1) {
        switch(option){
             case 'p' :
		    puerto=atoi(optarg);
             break;
             default:
		 printf("Modo de uso :  ./servidor -p [puerto] \n"); 
                 return -1;
	     break;
        }
    }   

   if ((fd=socket(AF_INET, SOCK_STREAM, 0))<0) {  
      perror("error socket");
      return -1;
   }

   server.sin_family = AF_INET;         
   server.sin_port = htons(puerto); 
   server.sin_addr.s_addr = INADDR_ANY; 
   
   setsockopt(fd,SOL_SOCKET, SO_REUSEADDR,(void *)&val,sizeof(val));//funcion para que no quede ocupado el socket al establecer nueva conexion
   if((bind(fd,(struct sockaddr*)&server,sizeof(struct sockaddr)))<0) {
      perror("error bind");
      return -1;
   }     

   listen(fd,2000);

   int leido,opcion,pid;
   char *name;
   socklen_t tamano=sizeof(struct sockaddr_in);
   signal(SIGCHLD,SIG_IGN);//funcion apara evitar que queden procesos zombies 
   while((fd2=accept(fd,(struct sockaddr *)&client,&tamano))>0){	
   	pid=fork();
	if(pid==0){
		printf("Conectado\n\n");
		if((leido=read(fd2,buffer, sizeof (buffer)))<0){
			perror("error read");
			errores(fd2,500,0);
			return -1;
		}
		write(STDOUT_FILENO,buffer,leido);
		opcion=extencion(buffer,leido);//analiza la extencion del archivo
		name=nombre(buffer,leido);//analiza el nombre del archivo
		respuesta(opcion,fd2,name);//envia la cabecera http y el archivo
		//memset(buffer,0,sizeof(buffer));
		printf("Desconectado\n");
		close(fd2);
		return 0;
     	}
        close(fd2);
  }
  close(fd);
  return 0;
}

