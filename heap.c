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

void swap(heapElem *a, heapElem *b){
  heapElem aux = *a;
  *a = *b;
  *b = aux;
  return;
}

void* heap_top(Heap* pq){
  if (pq == NULL || pq->size == 0)return NULL;
  return pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
  if (pq == NULL || pq->size == 0)return;
  if(pq->size == pq->capac){
    int newCapac = (pq->capac * 2) + 1;
    pq->heapArray = realloc(pq->heapArray, (newCapac * sizeof(heapElem)));
    if(pq->heapArray == NULL)return;
    pq->capac = newCapac;
  }

  int index = pq->size;
  pq->heapArray[index].data = data;
  pq->heapArray[index].priority = priority;
  pq->size++;

  while(index > 0 && pq->heapArray[(index - 1) / 2].priority < pq->heapArray[index].priority){
    swap(&pq->heapArray[(index - 1) / 2], &pq->heapArray[index]);
    index = (index - 1) / 2;
  }
  return;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *heap = (Heap*)malloc(sizeof(Heap));
  if (heap == NULL)return NULL;

  heap->heapArray = (heapElem*)malloc(3 * sizeof(heapElem));
  if (heap->heapArray == NULL){
    free(heap);
    return NULL;
  }

  heap->size = 0;
  heap->capac = 3;
  return heap;
}