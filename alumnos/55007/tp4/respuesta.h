#ifndef RESPUESTA_H
#define RESPUESTA_H

#include <stdio.h>
#include <stdlib.h>          
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "extencion.h"
#include "hora.h" 
#include <unistd.h>
#include <time.h>

void respuesta(int,int,char*);

#endif 
