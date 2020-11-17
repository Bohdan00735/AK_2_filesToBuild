
/*
 * Copyright (c) 2017, GlobalLogic Ukraine LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the GlobalLogic.
 * 4. Neither the name of the GlobalLogic nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GLOBALLOGIC UKRAINE LLC ``AS IS`` AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL GLOBALLOGIC UKRAINE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <linux/types.h>

MODULE_AUTHOR("Bohdan Melniichuk IO-81");
MODULE_DESCRIPTION("First training kernel module wich repeat phrase");
MODULE_LICENSE("Dual BSD/GPL");

static uint amount = 1;
module_param(amount,uint,0);
MODULE_PARM_DESC(amount, "That`s how many times the line should be printed");

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
    printk(KERN_INFO "Hello world!\n");
  }
  return 0;
}

static void __exit cleanup_function(void)
{
  /* Do nothing here right now */
}

module_init(init_function);
module_exit(cleanup_function);
