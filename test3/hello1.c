#include "hello1.h"

void print_hello(){
printk(KERN_INFO "Hello world!\n");
}

EXPORT_SYMBOL(print_hello);
