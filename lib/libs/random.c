#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

u_int64_t getUint64(void)
{
	u_int64_t retVal;
	int randomFd = open("/dev/urandom", O_RDONLY);
	if (randomFd == -1) {
		perror("open urandom failed");
		exit(-1);
	}
	ssize_t result = read(randomFd, &retVal, sizeof retVal);
	if (result == -1) {
		perror("read urandom failed");
		exit(-1);
	}
	close(randomFd);
	return retVal;
}

u_int32_t getUint32(void)
{
	u_int32_t retVal;
	int randomFd = open("/dev/urandom", O_RDONLY);
	if (randomFd == -1) {
		perror("open urandom failed");
		exit(-1);
	}
	ssize_t result = read(randomFd, &retVal, sizeof retVal);
	if (result == -1) {
		perror("read urandom failed");
		exit(-1);
	}
	close(randomFd);
	return retVal;
}

int32_t getInt32(void)
{
	int32_t retVal;
	int randomFd = open("/dev/urandom", O_RDONLY);
	if (randomFd == -1) {
		perror("open urandom failed");
		exit(-1);
	}
	ssize_t result = read(randomFd, &retVal, sizeof retVal);
	if (result == -1) {
		perror("read urandom failed");
		exit(-1);
	}
	close(randomFd);
	return retVal;
}
