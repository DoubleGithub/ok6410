/*
    Describe:Achieve independent keys drive by using of Interrupt
    Author:Double
    Date:2018-1-24
    Version:1.0
*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
static dev_t key_number;
static int key_major;
static struct cdev key_cdev;
static struct file_operations key_ops;
static void key_cdev_initial(void)
{
    printk(KERN_ALERT "%s\n", __FUNCTION__);
    alloc_chrdev_region(&key_number, 0, 1, "key drive");
    key_major = MAJOR(key_number);
    printk(KERN_ALERT "key_major=%d\n", key_major);
    key_cdev.owner = THIS_MODULE;
    key_cdev.dev = key_number;
    key_cdev.ops = &key_ops;
    key_cdev.count = 1;
    cdev_init(&key_cdev, &key_ops); 
    cdev_add(&key_cdev, key_number, 1);
}
static int __init key_init(void)
{
    printk(KERN_ALERT "%s\n", __FUNCTION__);
    key_cdev_initial();
    return 0;
}
static void __exit key_exit(void)
{
    printk(KERN_ALERT "%s\n", __FUNCTION__);
    unregister_chrdev_region(key_number, 1);
    cdev_del(&key_cdev);
}
module_init(key_init);
module_exit(key_exit);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Double");
