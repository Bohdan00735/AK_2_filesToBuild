#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <linux/types.h>

MODULE_AUTHOR("Bohdan Melniichuk IO-81");
MODULE_DESCRIPTION("Second training kernel module wich repeat phrase");
MODULE_LICENSE("Dual BSD/GPL");

extern void print_hello(void);
