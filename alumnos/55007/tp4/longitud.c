#include "longitud.h"

//struct stat {
//               dev_t     st_dev;     /* ID of device containing file */
//               ino_t     st_ino;     /* inode number */
//               mode_t    st_mode;    /* protection */
//               nlink_t   st_nlink;   /* number of hard links */
//               uid_t     st_uid;     /* user ID of owner */
//               gid_t     st_gid;     /* group ID of owner */
//               dev_t     st_rdev;    /* device ID (if special file) */
//               off_t     st_size;    /* total size, in bytes */
//               blksize_t st_blksize; /* blocksize for filesystem I/O */
//               blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
//               time_t    st_atime;   /* time of last access */
//               time_t    st_mtime;   /* time of last modification */
//               time_t    st_ctime;   /* time of last status change */
//           };
char *longitud(int file){
	struct stat buff;
	fstat(file, &buff);//int fstat(int fd, struct stat *buf);
	char *cad=malloc(50*sizeof(char));
	off_t tam = buff.st_size;	
	snprintf(cad,sizeof(tam), "%d\n",(int)tam);
	printf("Tamaño del archivo-----------> %s \n",cad);
return cad;
}
