
/*
 * Autor: Yair Alejandro Erreguin Franco
 * Descripción: Implementación de Biblioteca de Aritmética de Precisión múltiple (256 bits)
 * Fecha: 28/12/2025
 * .:DEFINICIONES:.
 * */

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
 * SIGNIFICADO DE CADA RETORNO
 * a > b ~  1
 * a < b ~ -1
 * a = b ~  0
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
