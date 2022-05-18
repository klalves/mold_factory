#ifndef _Queue_PRIVADO_H_
#define _Queue_PRIVADO_H_

#include "queue_publico.h"

// struct Item of Queue.
// struct Item
// {
//     int type;    // type of data.
//     size_t size; // size of data.
//     void *data;  // generic of data.
// };

// Struct Queue Heterogeneous Circular (Fila) - FIFO.
struct Queue
{
    // int remove; // start, head, front, remove.
    // int insert; // end, tail, rear, insert.
    // int size; // size of queue.
    // int used; // position in queue used.
    // struct Item **items;

    
    int size;
    int begin;
    int end;
    int *data_size;
    int *data_type;
    void **data;
       
};

#endif
