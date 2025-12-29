
/*
 * Autor: Yair Alejandro Erreguin Franco
 * Descripción: Implementación de Biblioteca de Aritmética de Precisión múltiple (256 bits)
 * Fecha: 28/12/2025
 * .:DEFINICIONES:.
 * */

//ARHCIVO DE CABECERAS
#include "mpa-256.h"

//IMPRESIÓN DE BIG NUM 256 
void bn_print(const bn256 *n)
{
  printf("0x");
  for(int i=WPN-1; i>=0; i--)
    printf("%08X", n->w[i]);
  printf("\n");
}


//INICIALIZACIÓN DE UN BIG NUM 256
int bn_init(bn256 *n)
{
  n->w = (uint32_t*)calloc(WPN, sizeof(uint32_t));
  if(!(n->w)) return -1;
  return 1;
}

//LIBERACIÓN DE UN BIG NUM 256
int bn_free(bn256 *n)
{
  if(n->w != NULL)
  {
    free(n->w);
    n->w = NULL;
    return 1;
  }
  return -1;
}

//RELACIÓN DE ORDEN PARA DOS BIG NUM 256
/*
 * RETORNA:
 *  1 SI a>b
 * -1 SI a<b
 *  0 SI a=b
 * */
int bn_cmp(const bn256 *a, const bn256 *b)
{
  for(int i=WPN-1; i>=0; i--)
  {
    if(a->w[i] > b->w[i]) return 1;
    else if(a->w[i] < b->w[i]) return -1;
  }
  return 0;
}

//ASIGNACIÓN DE UN BIG NUM 256 A PARTIR DE OTRO
int bn_cpy(bn256 *dest, const bn256 *src)
{
  if(dest->w != NULL && src->w != NULL)
  { 
    for(int i=WPN-1; i>=0; i--)
      dest->w[i] = src->w[i];
    return 1;
  }
  return -1;
}

//SUMA DE DOS BIG NUM 256
/*
 * RETORNA:
 *  -1 SI EXISTE UN PROBLEMA DE MEMORIA; APUNTADORES NULOS.
 *   0 SI NO EXISTE OVERFLOW
 *   1 SI EXISTE OVERFLOW
 * */
int bn_add(bn256 *res, const bn256 *a, const bn256 *b)
{
  if(res->w == NULL || a->w == NULL || b->w == NULL) return -1;
  
  uint64_t carry = 0;

  for(int i=0; i<WPN; i++)
  {
    carry = (uint64_t)a->w[i] + b->w[i] + carry;
    res->w[i] = (uint32_t)carry; //carry & 0xFFFFFFFF
    carry >>= 32;
  }
  return (int)carry;
}

//RESTA DE DOS BIG NUM 256
/*
 * RETORNA:
 *  -1 SI EXISTE UN PROBLEMA DE MEMORIA; APUNTADORES NULOS.
 *   0 SI NO EXISTE UNDERFLOW
 *   1 SI EXISTE UNDERFLOW
 * */
int bn_sub(bn256 *res, const bn256 *a, const bn256 *b)
{
  if(res->w == NULL || a->w == NULL || b->w == NULL) return -1;

  uint64_t borrow = 0;
  uint64_t temp = 0;

  for(int i=0; i<WPN; i++)
  {
    temp = (uint64_t)a->w[i] - b->w[i] - borrow;
    res->w[i] = (uint32_t)temp;
    borrow = (temp>>32)&1;
  }
  return (int)borrow;
}
