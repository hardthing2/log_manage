obj-m=testko.o




all:test
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) -I. modules;



test:test.c
	gcc -o $@ $< -L. -llog_user -I.


clean:
	make -C /lib/modules/(shell uname -r)/build M=(shell pwd) -I. clean;

