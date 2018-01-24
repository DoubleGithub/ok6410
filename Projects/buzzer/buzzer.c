#include <linux/module.h>
#include <linux/init.h>
static int __init buzzer_init(void)
{
	return 0;
}
static void __exit buzzer_exit(void)
{
}
module_init(buzzer_init);
module_exit(buzzer_exit);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("DOUBLE");
