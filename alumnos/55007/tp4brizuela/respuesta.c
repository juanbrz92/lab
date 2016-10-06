#include "respuesta.h"
#include "errores.h"
#include "hora.h"
#include "longitud.h"
#include <errno.h>
void respuesta(int opcion,int fd2,char* name){
	char buffer2[10000],*len;
	int leido2,hd,hd2,file;
	switch(opcion){
			case 1:
				if((file=open(name,O_RDONLY))>0){
					len=longitud(file);
					errores(fd2,1,len);
					lseek(file,0,SEEK_SET);
					while((leido2=read(file,buffer2,sizeof(buffer2)))>0){				
						write(fd2,buffer2,leido2);
					}
					close(file);
				}else{
				        errores(fd2,404,NULL);
				}
			break;
			case 2:
                                if((file=open(name,O_RDONLY))>0){
                                        len=longitud(file);
                                        errores(fd2,1,len);
                                        lseek(file,0,SEEK_SET);
                                        while((leido2=read(file,buffer2,sizeof(buffer2)))>0){
                                                write(fd2,buffer2,leido2);
                                        }
					close(file);
                                }else{
                                        errores(fd2,404,NULL);
                                }
			break;
			case 3:
                                if((file=open(name,O_RDONLY))>0){
                                        len=longitud(file);
                                        errores(fd2,2,len);
                                        lseek(file,0,SEEK_SET);
                                        while((leido2=read(file,buffer2,sizeof(buffer2)))>0){
                                                write(fd2,buffer2,leido2);
                                        }
					close(file);
                                }else{
                                        errores(fd2,404,NULL);
                                }
                        break;
			case 4:
                                if((file=open(name,O_RDONLY))>0){
                                        len=longitud(file);
                                        errores(fd2,3,len);
                                        lseek(file,0,SEEK_SET);
                                        while((leido2=read(file,buffer2,sizeof(buffer2)))>0){
                                                write(fd2,buffer2,leido2);
                                        }
					close(file);
                                }else{
                                        errores(fd2,404,NULL);
                                }
                        break;
			default:
				if(name==NULL){
					hd=open("head.txt",O_RDONLY);
                                        while ((leido2=read(hd,buffer2,sizeof(buffer2)))>0){
                                                write(fd2,buffer2,leido2);
                                        }
                                        close(hd);
                                        hd2=open("default2.html",O_RDONLY);
                                        while ((leido2=read(hd2,buffer2,sizeof(buffer2)))>0){
                                                write(fd2,buffer2,leido2);
                                        }
                                        close(hd2);	
				}else{
					hd=open("head.txt",O_RDONLY);
					while ((leido2=read(hd,buffer2,sizeof(buffer2)))>0){
						write(fd2,buffer2,leido2);
					}
					close(hd);
					hd2=open("default.html",O_RDONLY);
                        	        while ((leido2=read(hd2,buffer2,sizeof(buffer2)))>0){
                        	                write(fd2,buffer2,leido2);
                        	        }
                        	        close(hd2);
				}
			break;
				
		}
}
