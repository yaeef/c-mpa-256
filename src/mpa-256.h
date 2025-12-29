
/*
 * Autor: Yair Alejandro Erreguin Franco
 * Descripción: Implementación de Biblioteca de Aritmética de Precisión múltiple (256 bits)
 * Fecha: 28/12/2025
 * .:PROTOTIPOS:.
 * */

//GUARDA DE CABECERA INICIO
#ifndef MPA_256_H
#define MPA_256_H

//BIBLIOTECA PARA USO DE MEMORIA DINAMICA
#include <stdlib.h>

//BIBLIOTECA PARA USO DE ENTRADAS Y SALIDAS
#include <stdio.h>

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
void bn_print(const bn256* );
int bn_init(bn256* );
int bn_free(bn256* );
int bn_cmp(const bn256*, const bn256* );
int bn_cpy(bn256*, const bn256* );
int bn_add(bn256*, const bn256*, const bn256* );
int bn_sub(bn256*, const bn256*, const bn256* );





//GUARDA DE CABECERA FIN
#endif
