#include "read.h"
static THD_WORKING_AREA(wa_read_thread, 256);
static THD_FUNCTION(read_thread, arg) {
(void) arg;
}














void readSetup(){
  chThdCreateStatic(wa_read_thread, sizeof(wa_read_thread),
      NORMALPRIO, read_thread, NULL);
}
