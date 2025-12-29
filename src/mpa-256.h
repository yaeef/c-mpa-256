
/*
 * Autor: Yair Alejandro Erreguin Franco
 * Descripción: Implementación de Biblioteca de Aritmética de Precisión múltiple (256 bits)
 * Fecha: 28/12/2025
 * .:PROTOTIPOS:.
 * */

//BIBLIOTECA PARA USO DE MEMORIA DINAMICA
#include <stdlib.h>

//BIBLIOTECA PARA USO DE "uint_32"
#include <stdint.h>


//CANTIDAD DE PALABRAS POR NUMERO
#define WPN 8

//ESTRUCTURA PARA UN NÚMERO DE 256 BITS LITTLE-ENDIAN
typedef struct
{
  uint32_t *w;
}bn256;

//PROTOTIPOS
int bn_init(bn256* );
int bn_free(bn256* );
int bn_cmp(const bn256*, const bn256* );






#include "mpa-256.c"
