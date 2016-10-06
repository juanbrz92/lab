#include "hora.h"

int hora(int fd) {
	time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[22];
	memset(output,0,sizeof(output));	
        strftime(output,128,"%a %d/%m/%y %H:%M:%S",tlocal);
	strcat(output,"\n");
        write(fd,output,sizeof(output));
	
        return 0;
}

