/*
	Describe:zzer device
	Drive:ok6410
	Author:double 
	Date:2018-1-20
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <asm/io.h>
static dev_t buzzer_no;
static int buzzer_major;
static struct cdev buzzer_cdev;
static int *address = NULL;
static ssize_t buzzer_read(struct file *fp, char __user *buff, size_t num, loff_t *ploff)
{
	printk(KERN_ALERT "%s\n", __FUNCTION__);
	return num;
}
static ssize_t buzzer_write(struct file *fp, const char __user *buff, size_t num, loff_t *ploff)
{
	printk(KERN_ALERT "%s\n", __FUNCTION__);
	return num;
}
static void buzzer_start(void)  //write control date to GPxDAT
{
	unsigned int value = 0;
	value = ioread32(address + 1); //because the address if type of int *
	printk(KERN_ALERT "before modify GPFDAT value = %x\n", value);
	value &= 0x7FFF;
	value |= 0x1 << 15;
	printk(KERN_ALERT "after modify GPFDAT value = %x\n", value);
	iowrite32(value, address + 1);
}
static void buzzer_stop(void)   //write control date to GPxDAT
{
	unsigned int value = 0;
	value = ioread32(address + 1); //because the address if type of int *
	printk(KERN_ALERT "before modify GPFDAT value = %x\n", value);
	value &= 0x7FFF;
	//value |= 0x1<<15;
	printk(KERN_ALERT "after modify GPFDAT value = %x\n", value);
	iowrite32(value, address + 1);
}
static long buzzer_unlocked_ioctl(struct file *fp, unsigned int cmd, unsigned long param)
{
	printk(KERN_ALERT "%s\n", __FUNCTION__);
	switch (cmd)
	{
	case 1:
		buzzer_start();
		break;
	default:
		buzzer_stop();
		break;
	}
	return cmd;
}
static int buzzer_open(struct inode *pnode, struct file *fp)
{
	unsigned int value = 0;
	printk(KERN_ALERT "%s\n", __FUNCTION__);
	address = ioremap(0x7F0080A0, 8);
	value = ioread32(address);
	printk(KERN_ALERT "before modify value = %x\n", value);
	value &= 0x3FFFFFFF; //置31-30为0 00xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	value |= 0x40000000;  //
	printk(KERN_ALERT "after modify value = %x\n", value);
	iowrite32(value, address);

	return 0;
}
int buzzer_release(struct inode *pnode, struct file *fp)
{
	printk(KERN_ALERT "%s\n", __FUNCTION__);
	return 0;
}
static struct file_operations buzzer_ops =
{ 
	.owner = THIS_MODULE,
	.read = buzzer_read,
	.release = buzzer_release,
	.open = buzzer_open,
	.write = buzzer_write,
	.unlocked_ioctl = buzzer_unlocked_ioctl,
};
static int __init buzzer_init(void)
{
	printk(KERN_ALERT "%s\n", __FUNCTION__);
	//int alloc_chrdev_region(dev_t * dev, unsigned baseminor, unsigned count, const char * name);
	alloc_chrdev_region(&buzzer_no, 0, 1, "buzzer device");
	buzzer_major = MAJOR(buzzer_no);
	printk(KERN_ALERT "major=%d\n", buzzer_major);

	buzzer_cdev.owner = THIS_MODULE;
	buzzer_cdev.ops = &buzzer_ops;
	buzzer_cdev.dev = buzzer_no;
	buzzer_cdev.count = 1;

	cdev_init(&buzzer_cdev, &buzzer_ops);
	cdev_add(&buzzer_cdev, buzzer_no, 1);

	return 0;
}
static void __exit buzzer_exit(void)
{
	printk(KERN_ALERT "%s\n", __FUNCTION__);

	unregister_chrdev_region(buzzer_no, 1);
	cdev_del(&buzzer_cdev);
}
MODULE_LICENSE("Dual BSD/GPL");
module_init(buzzer_init);
module_exit(buzzer_exit);
