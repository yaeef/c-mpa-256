/*
 * SCRIPT DE PRUEBA
 * */


#include <stdio.h>
#include "mpa-256.h"

int main(int argc, char **argv)
{
  bn256 n,a,b;
  bn_init(&n);
  bn_init(&a);
  bn_init(&b);
  
  a.w[0] = 0x000001F4; //500

  b.w[0] = 0x000001F3; //499

  n.w[0] = 0xFFFFFC2F; //LSB
  n.w[1] = 0xFFFFFFFE;
  n.w[2] = 0xFFFFFFFF;
  n.w[3] = 0xFFFFFFFF;
  n.w[4] = 0xFFFFFFFF;
  n.w[5] = 0xFFFFFFFF;
  n.w[6] = 0xFFFFFFFF;
  n.w[7] = 0xFFFFFFFF;  //MSB

  printf("%d", bn_cmp(&a, &b));

  bn_free(&b);
  bn_free(&a);
  bn_free(&n);
  return 0;
} 
