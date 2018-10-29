#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "work10.h"

int main() {
	umask(0000);
	int i = 0;
	int randos[10];
	int reados[10];

	printf("Populating array with random numbers:\n");
	for (; i < 10; i++) {
		randos[i] = random_int();
		printf("\trandom %d: %d\n", i, randos[i]);
	}

	printf("\nWriting random numbers to file...\n\n");
	int fd_write = open("sample.txt", O_CREAT | O_RDWR, 0655);
	if (write(fd_write, &randos, sizeof(randos)) == -1)
		printf("couldn't write: %s\n", strerror(errno));
	if (close(fd_write) == -1)
		printf("couldn't close: %s\n", strerror(errno));

	printf("Reading numbers from file...\n\n");
	int fd_read = open("sample.txt", O_RDONLY);
	if (read(fd_read, &reados, sizeof(reados)) == -1)
		printf("couldn't write: %s\n", strerror(errno));
	if (close(fd_read) == -1)
		printf("couldn't close: %s\n", strerror(errno));

	printf("Verification that written values were the same:\n");
	for (i = 0; i < 10; i++)
		printf("\trandom %d: %d\n", i, reados[i]);

	return 0;
}