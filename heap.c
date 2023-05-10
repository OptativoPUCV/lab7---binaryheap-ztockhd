#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
  Heap *nuevo = pq;
  if(nuevo->heapArray == NULL)
  {
    free(nuevo);
    return NULL;
  }

  void* dato = nuevo->heapArray->data;
  return dato;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap *nuevo = malloc(sizeof(Heap));
  if(nuevo == NULL) return NULL;
  nuevo->heapArray = malloc(3 *sizeof(Heap));
  if(nuevo->heapArray == NULL)
  {
    free(nuevo);
    return NULL;
  }
  nuevo->size = 0;
  nuevo->capac = 3;

  return nuevo;
}
