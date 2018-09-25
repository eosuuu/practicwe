#include <linux/init.h>
#include <linux/module.h>

int __init hello_init(void)
{
	printk("Hello!\n");
	return 0;
}

void __exit hello_exit(void)
{
	printk("Goodbye!\n");
}


module_init(hello_init);
module_exit(hello_exit);
