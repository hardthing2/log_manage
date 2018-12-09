#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "log.h"

int main()
{
	char *log;
	log = (char *)malloc(10000);
	printf_kernel(log);
	printf("%s",log);
	return 0;
}
