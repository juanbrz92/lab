#ifndef CONTAR_H
#define CONTAR_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <getopt.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<semaphore.h>
#include<sys/wait.h>

int *contar(char*,int);

#endif 


