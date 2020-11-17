#include "hello1.h"

static uint amount =1;
module_param(amount,uint,0);
MODULE_PARM_DESC(amount, "That`s how many times the line should be printed");
EXPORT_SYMBOL(amount);

static int __init init_function(void)
{
  uint i = 1;

  printk(KERN_INFO "amount: %d\n", amount);

  if(amount == 0) {
    printk(KERN_WARNING "The parameter is 0");
  }else if(amount < 0) {
    printk(KERN_WARNING "Number should be positive");
    return 0;
  }else if(amount >=5 && amount <= 10) {
    printk(KERN_WARNING "The parameter is between 5 and 10");
  } else if(amount > 10) {
    printk(KERN_ERR "The parameter is greater than 10");
    return -EINVAL;
  }

  for(i = 0; i < amount; i++){
    print_hello();
  }
  return 0;
}

static void __exit cleanup_function(void)
{
  /* Do nothing here right now */
}

module_init(init_function);
module_exit(cleanup_function);
