#include <linux/module.h>
#include <linux/init.h>
#include "add_sub.h"
static int a = 1;
static int b = 1;
static int AddORSub = 1;
static int __init test_init(void)
{
    static int result = 0;
    printk(KERN_ALERT "%s\n", __FUNCTION__);
    if (AddORSub == 1)
    {
		result = add_integer(a, b);
    } else
    {
        result = sub_integer(a, b);
    }
    printk(KERN_ALERT "The %s result is %d\n", AddORSub == 1 ? "Add" : "Sub", result); 
    return 0;
}
static void __exit test_exit(void)
{
    printk(KERN_ALERT "%s\n", __FUNCTION__);
}
module_init(test_init);
module_exit(test_exit);
module_param(a, int, S_IRUGO);
module_param(b, int, S_IRUGO);
module_param(AddORSub, int, S_IRUGO);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Double");
