#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO  SUCCESS
#define FRACASSO FAIL

// typedef struct Item *pItem, **ppItem;
typedef struct Queue *pQueue, **ppQueue;

// // struct Item of Queue.
// struct ItemQueue
// {
//     int type;       // type of data.
//     size_t size;    // size of data.
//     void *data;     // generic of data.
// };

int init(ppQueue pp, int size, int size_data_max);
int destroy(ppQueue pp);
int enqueue(pQueue p, void *data, int data_size, int data_type);
int dequeue(pQueue p, void *data, int *data_type);

//******************************

// int init(int size);
// int destroy(ppQueue q);

// void enqueue(pQueue q, void *data, int type, size_t size);
// void dequeue(pQueue q, void *data, int *type, size_t *size);

// void enqueue3(pQueue q, struct ItemQueue item);
// void dequeue3(pQueue q, struct ItemQueue *size);

int isEmpty(pQueue q);
int isFull(pQueue q);

void printInfo(pQueue q);

