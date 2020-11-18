#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <linux/types.h>

MODULE_AUTHOR("Melniichuk Bohdan IO-81");
MODULE_DESCRIPTION("First training kernel module wich repeat phrase");
MODULE_LICENSE("Dual BSD/GPL");

extern void print_hello(void);

