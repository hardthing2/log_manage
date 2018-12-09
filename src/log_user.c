#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include "log.h"
#include <sys/mman.h>
#include <unistd.h>

int main()
{
        int ret = 0;
        int fd;
        long arg;
        char *shared_mem;
        fd = open("/dev/dipper_log",O_RDWR);
        
        shared_mem = (char*)mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
        while(1)
        {
                sleep(1);
                printf("%s\n\r", shared_mem);
        }
        close(fd);
}
