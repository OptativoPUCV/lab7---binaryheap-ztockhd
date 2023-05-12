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
  if(pq->size == 0)
  {
    return NULL;
  }
  return pq->heapArray[0].data;;
}



void heap_push(Heap* pq, void* data, int priority)
{
  int i = pq -> size;
  
  if(pq -> size == pq -> capac)
  {
    pq -> capac = pq -> capac * 2 + 1;
    pq -> heapArray = realloc(pq -> heapArray, pq -> capac * sizeof(heapElem));
  }

  while (i > 0 && priority > pq -> heapArray[(i - 1) / 2].priority)
  {
    pq -> heapArray[i] = pq -> heapArray[(i - 1) / 2];
    i = (i - 1) / 2;
  }

  pq -> heapArray[i].data = data;
  pq -> heapArray[i].priority = priority;
  pq -> size++;
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
