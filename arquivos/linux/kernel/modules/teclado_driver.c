/*
KVER := $(shell uname -r)
KDIR := /usr/src/linux-headers-$(KVER)
PWD  := $(shell pwd)
 
obj-m += teclado_driver.o
 
default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules


sudo insmod teclado_driver.ko
sudo rmmod teclado_driver

prob­lema: emu­lar um teclado vir­tual inde­pen­dente de bib­lioteca grá­fica, e que fun­cione em modo texto.

a imple­men­tação do teclado PS2 padrão encontra-se nos fontes do ker­nel em drivers/input/keyboard/atkbd.c. 

Após ler os scan­codes, o device dri­ver irá convertê-los em um outro código chamado key­codes.
$ sudo showkey -s
$ sudo showkey -k

A camada 0 é hard­ware, e não temos hard­ware no nosso caso.
A camada 2 é genérica, e não é uma boa prática mexer nela.
Portanto, é na camada 1 que tra­bal­hare­mos.

Vamos desen­volver um device dri­ver (no nosso caso, um módulo do ker­nel, já que não falare­mos com nen­hum hard­ware) que irá gerar even­tos de teclado para a camada input.

O mód­ulo irá emu­lar a dig­i­tação de uma frase a cada 10 segun­dos: a frase “dig­i­tada” pelo módulo será “seg­men­ta­tion fault”!
*/

#include "linux/fs.h"
#include "linux/cdev.h"
#include "linux/module.h"
#include "linux/kernel.h"
#include "linux/delay.h"
#include "linux/kthread.h"
#include "linux/device.h"
#include "linux/slab.h"
#include "linux/tty.h"
#include "linux/tty_flip.h"
#include "linux/kbd_kern.h"
#include "linux/input.h"
 
// vtkbd kernel thread struct
static struct task_struct *vtkbd_thread_task;
 
// vtkbd input device structure
static struct input_dev *vtkbd_input_dev;
 
// str_keys[] con­tém os key­codes para a frase "seg­men­ta­tion fault\n". Esses key­codes estão definidos em include/linux/input.h.
const char str_keys[] = { KEY_S, KEY_E, KEY_G, KEY_M, KEY_E, KEY_N, KEY_T, KEY_A, KEY_T, KEY_I, KEY_O, KEY_N, KEY_SPACE, KEY_F, KEY_A, KEY_U, KEY_L, KEY_T, KEY_ENTER };

// kernel thread
static int vtkbd_thread(void *unused) {
   int i;
   
   while (!kthread_should_stop()) {
      for (i = 0; i < sizeof(str_keys); i++) {
         input_report_key(vtkbd_input_dev, str_keys[i], 1); // simula a tecla pressionada
         input_report_key(vtkbd_input_dev, str_keys[i], 0); // simula a tecla liberada
         input_sync(vtkbd_input_dev); // noti­f­i­ca a camada input da existên­cia de novos even­tos a serem tratados.
      }
      
      // wait 10 seconds
      msleep(10000);
   }
   
   return(0);
}
 
// driver initialization
static int __init vtkbd_init(void) {
   static const char *name = "Virtual Keyboard";
   int i;
   
   // input_allocate_device() devolve uma estru­tura que pos­si­bil­i­ta con­ver­sar com a camada input e gerar os even­tos de teclado.
   // allocate input device
   vtkbd_input_dev = input_allocate_device();
   if (!vtkbd_input_dev) {
      printk("vtkbd_init: Error on input_allocate_device!\n");
      return -ENOMEM;
   }
    
   // set input device name
   vtkbd_input_dev->name = name;
   
   // enable key events em todas as teclas
   set_bit(EV_KEY, vtkbd_input_dev->evbit);
   for (i = 0; i < 256; i++) set_bit(i, vtkbd_input_dev->keybit);
   
   // register input device
   input_register_device(vtkbd_input_dev);
   
   // start thread
   vtkbd_thread_task = kthread_run(vtkbd_thread, NULL, "%s", "vtkbd_thread");
   
   printk("Virtual Keyboard driver initialized.\n");
   
   return 0;
}

// driver exit
void __exit vtkbd_exit(void) {
   // stop thread
   kthread_stop(vtkbd_thread_task);
   
   // unregister input device
   input_unregister_device(vtkbd_input_dev);
   
   printk("Virtual Keyboard driver.\n");
}

module_init(vtkbd_init);
module_exit(vtkbd_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergio Prado sergio.prado@embeddedlabworks.com");
MODULE_DESCRIPTION("Virtual Keyboard driver");

