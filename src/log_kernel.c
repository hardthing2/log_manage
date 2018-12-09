#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/slab.h>

unsigned int major;
dev_t devno;
struct class *cls = {0};
char *shared_mem = NULL;

int log_write(char *content)
{

        return 0;
}

int dipper_open(struct inode *a, struct file *b)
{
        printk("hello\n");
        return 0;
}

 

static int dipper_map(struct file *fd, struct vm_area_struct *vma)
{
        unsigned long page;
        page = virt_to_phys(shared_mem);
        remap_pfn_range(vma, (unsigned long)vma->vm_start, page>>PAGE_SHIFT, (unsigned long)(vma->vm_end - vma->vm_start), PAGE_SHARED);
        *shared_mem = 100;
        return 0;
}

struct file_operations dipper_log_fop=
{
        .open = dipper_open,
        .mmap = dipper_map,
};

static int log_init(void)
{
        int ret;
        int minor;
        shared_mem = (char *)kmalloc(4096, GFP_KERNEL);
        ret = register_chrdev(0, "dipper_log", &dipper_log_fop);
        if (ret < 0)
        {
                printk("register_chrdev failed!\n\r");
        }
        else
        {
                printk("register_chrdev succeed!the ret num is %d\n\r", ret);
        }
        major = ret;
        minor = 0;
        devno = MKDEV(major, minor);

        cls = class_create(THIS_MODULE, "logclass");
        device_create(cls, NULL, devno, NULL, "dipper_log");
        return 0;
}

static void log_exit(void)
{
        device_destroy(cls, devno);
        class_destroy(cls);
        unregister_chrdev(major, "dipper_log");
        return;
}




MODULE_LICENSE("GPL");
module_init(log_init);
module_exit(log_exit);
