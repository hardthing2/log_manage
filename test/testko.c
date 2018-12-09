#include <linux/module.h>
#include "log.h"


int aaa(void)
{
	log_write("helloworld!!\n\r");
	return 0;
}

void bbb(void)
{
	log_write("goodbye!!\n\r");
	return;
}


module_init(aaa);
module_exit(bbb);
