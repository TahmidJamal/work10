#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int random_int() {
	int fd = open("/dev/random", O_RDONLY);
	if ( fd == -1) {
		printf("couldn't open: %s\n", strerror(errno));
		return 0;
	}

	int rando;	
	if (read(fd, &rando, sizeof(int)) == -1 ) {
		printf("couldn't read: %s\n", strerror(errno));
	}
	if (close(fd) == -1) {
		printf("couldn't close: %s\n", strerror(errno));
	}
	return rando;
}