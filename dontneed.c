#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/** 

dontneed.c 

applies POSIX_FADV_DONTNEED to the specified file

**/

int main (int argc, char *argv[]) {
	
	if (argc != 2) {
		printf ("Usage: %s filename\n\n", argv[0]);
		printf ("Applies POSIX_FADV_DONTNEED to the specified file.\n\n");
		exit(1);
	}
	
	char* path = argv[1];
	
	char* mode = "POSIX_FADV_DONTNEED";
	
	int flags = O_RDONLY;
	int fd = open ( path, flags);
	if ( fd == -1 ) {
		fprintf (stderr, "Could not open file %s\n", path);
		return 1;
	}
	
	struct stat fd_stat;
	
	if (fstat (fd, &fd_stat ) < 0 ) {
		fprintf (stderr, "Could not stat file %s\n", path);
		return 1;
	}
	
	loff_t offset = 0;
	loff_t length = fd_stat.st_size;
	
	int result = posix_fadvise(fd, offset, length, POSIX_FADV_DONTNEED);
	if (result != 0){
		fprintf(stderr, "Could not set POSIX_FADV_DONTNEED for file %s\n",path);
	}
	close(fd);
	return 0;
}
