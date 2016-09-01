#include "contar.h"
#include "mostrar.h"
#include <string.h>
int main(int argc , char *argv[]){
        //contrl n para autocompletar
	char buffer[50];
	int leido,i,fd,fd1,bytes=0,tam=0;
	char *ptr;
	int *sem;
	int *cuenta,*ptr2;

	ptr=mmap(NULL,sizeof(buffer),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);
        sem = mmap(NULL,sizeof(sem_t)+20,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);
        ptr2=sem + sizeof(sem_t);
        sem_init(sem,1,0);//LO INICIALIZO EN cero

	fd1=open(argv[1],O_RDWR);
	while((leido=read(fd1,buffer,sizeof(buffer)))>0){
                tam=tam+leido;
        }
        printf("tamano del archivo = %d\n",tam);
        close(fd1);

	//tamanio(argv[1]);//funcion que muestra el tamaño del archivo;

	fd=open(argv[1],O_RDWR);
	while((leido=read(fd,buffer,sizeof(buffer)))>0){
		bytes=bytes+leido;
		strcpy(ptr,buffer);
		for(i=0;i<sizeof(buffer);i++){
			buffer[i]=0;
		}
		if(fork()==0){//hijo
			printf("%s",ptr);
			cuenta=contar(ptr,leido);
			for(i=0;i<20;i++){
				*(ptr2 + i) += cuenta[i];
			}
			sem_post(sem);//el hijo cuenta las palabras y las acumula en el vector ptr2 compartido
			return 0;
		}
		//padre
        	sem_wait(sem);//el padre se bloquea de modo que trabaja el hijo
		if(tam==bytes){
			 mostrar(ptr2);
		}else{
			continue;//si no cumple la condicion de que es la ultima iteracion, el prgrma continua normalmente
		}
	}
	close(fd);
	return 0;
}
