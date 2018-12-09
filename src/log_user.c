#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include "log.h"
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int log_user_write()
{
	
	return 0;
}

int printf_kernel(char* log)
{
	int fd;
	char *shared_mem;
	fd = open("/dev/dipper_log",O_RDWR);
	shared_mem = (char*)mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	printf("%s\n\r", shared_mem);
	strcpy(log, shared_mem);
	return 0;
}
