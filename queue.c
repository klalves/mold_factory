#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_privado.h"

/*
    Param size: size of queue.

    Return pQueue: pointer of struct of Queue initialized.
*/
int init(ppQueue pp, int size, int size_data_max)
{
    // check if params is valid.
    if (size <= 0)
    {
        return FRACASSO;
    }

    // Aloca memoria para Queue.
    (*pp) = (struct Queue *)malloc(sizeof(struct Queue));
    if ((*pp) == NULL)
    {
        return FRACASSO;
    }

    // allocate vector of (* void), of size_stack for data.
    (*pp)->data = (void **)malloc(size * sizeof(void *));
    if ((*pp)->data == NULL)
    {
        free(*pp);
        (*pp) = NULL;
        return FRACASSO;
    }

    (*pp)->data_size = malloc(size * sizeof(int *));

    (*pp)->data_type = malloc(size * sizeof(int *));

    // for(int i = 0; i < size_stack; i++)
    // {
    //     (*pp)->data[i] = malloc(size_data);
    //     if ((*pp)->data[i] == NULL)
    //     {
    //         for (--i; i > 0; i--)
    //         {
    //             free((*pp)->data[i]);
    //         }
    //         free((*pp)->data);
    //         free(*pp);
    //         (*pp) = NULL;
    //         return FRACASSO;
    //     }
    // }

        
    // inicialliza controle da Queue.
    //(*pp)->remove = -1;
    //(*pp)->insert = -1;
    (*pp)->begin = -1;
    (*pp)->end = -1;
    (*pp)->size = size;
    //p->used = 0;

    return SUCESSO;
}


int destroy(ppQueue pp)
{
     if ((*pp) == NULL)
    {
        return FRACASSO;
    }
    for (int i = 0; i < (*pp)->size; i++)
        free((*pp)->data[i]);
    free((*pp)->data);
    free(*pp);
    (*pp) = NULL;

    return SUCESSO;
}

void printInfo(pQueue p)
{
    //printf("remove: %2d, insert: %2d, used: %2d, size: %2d.", p->remove, p->insert, p->used, p->size);
}

int isEmpty(pQueue p)
{
    if (p == NULL)
        return -1;

    // verificando os limites de queue circular.
    return (p->begin == p->end);
}

int isFull(pQueue p)
{
    if (p == NULL)
        return -1;

    // verificando os limites de queue circular.
    return ((p->end + 1) % p->size == p->begin);
    
}
/*
    Param p: pointer iitialized of queue.
    Param type: type of 'data in' queue.
    Param size: size of 'data in' queue.

    Return: void.
*/
int enqueue(pQueue p, void *data, int data_size, int data_type)
{
    
    // check if params is valid.
    if (data_size < 0)
    {
        return FRACASSO;
    }
    
    // Verificar se a fila está cheia.
    if (p->size == p->begin){
			return FRACASSO;
	} else {
	// movimenta 'insert' para proxima posição para colocar Item, verificando os limites de queue circular.
	p->end = (p->end + 1) > (p->size - 1) ? 0 : p->end + 1;

    // atribui data.
    p->data[p->end] = malloc(data_size);
    memcpy(p->data[p->end], data, data_size);

    // atribui type.
    p->data_type[p->end] = data_type;

    // atribui sizeof data.
    p->data_size[p->end] = data_size;

    //p->used++;
    return SUCESSO;
	}
}

int dequeue(pQueue p, void *data, int *type)
{
    // movimenta 'front' para proxima posição para retirar Item, verificando os limites de queue circular.
    p->begin = (p->begin + 1) > (p->size - 1) ? 0 : p->begin + 1;
    
    memcpy(data, p->data[p->begin], p->data_size[p->begin]);
    memcpy(type, &(p->data_type[p->begin]), sizeof(int));
    // memcpy(size, &(p->items[p->remove])->size, sizeof(size_t));
    
    // free memory data, for new allocation next enqueue.
    free((p->data[p->begin]));
    p->data[p->begin] = NULL;

    // p->used--;

    return SUCESSO;
}
