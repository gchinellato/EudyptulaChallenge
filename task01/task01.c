#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int task01_init(void)
{
	printk(KERN_DEBUG "Hello World!\n");
	return 0;
}

static void task01_exit(void) 
{
	printk(KERN_DEBUG "Unloading task01 module\n");
}

module_init(task01_init);
module_exit(task01_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("gchinellato");
MODULE_DESCRIPTION("Task 01");
MODULE_VERSION("0.1");
