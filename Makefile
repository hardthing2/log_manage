obj-m+=./src/log_kernel.o


all:./release/log_user.so
	make -C $(LIBS) -I ./include M=$(shell pwd) modules;

./release/log_user.so:./src/log_user.c
	$(CC) $< -I ./include -shared -fPIC -o $@

clean:
	make -C $(LIBS) M=$(shell pwd) clean;



