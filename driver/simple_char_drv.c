#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

int simple_open (struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "Open simple char drv\n");
	return 0;
}

ssize_t simple_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "Read simple char drv\n");
	return 0;
}

ssize_t simple_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "Write simple char drv\n");
	return length;
}

int simple_close (struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "Release simple char drv\n");
	return 0;
}

struct file_operations fop = {
	.owner = THIS_MODULE,
	.open = simple_open,
	.read = simple_read,
	.write = simple_write,
	.release = simple_close, 
};
int __init simple_init(void)
{
	printk(KERN_ALERT "Init simple char drv\n");
	register_chrdev(240, "Simple char drv", &fop);
	return 0;
}

void __exit simple_exit(void)
{
	printk(KERN_ALERT "Exit simple char drv\n");
	unregister_chrdev(240, "Simple char drv");
}

module_init(simple_init);
module_exit(simple_exit); 
