/*************************************************************
 * Color queue model developed in the context
 * of the PAA Discipline
 *************************************************************/

#include "color_queue_private.h"

/********************************/
/* Internal Handlers Prototypes */
/********************************/


/**********************/
/* Creation operation */
/**********************/
int color_queue_init(pp_color_queue_t pp_color_queue, int queue_size){
    /* Memory allocation */
    (*pp_color_queue) = (p_color_queue_t)malloc(sizeof(color_queue_t));
    if( (*pp_color_queue) == NULL ) return FAIL;

    return init(&((*pp_color_queue)->queue), queue_size, sizeof(color_t));
}


/*************************/
/* Destruction operation */
/*************************/
int color_queue_destroy(ppFila pp_color_queue){
    destroy(&((*pp_color_queue)->queue));
    free(*pp_color_queue);
    return SUCCESS;
}


/*********************/
/* Access operations */
/*********************/


/***************************/
/* Manipulation operations */
/***************************/

/*-------------------------------------------------------------------------*/
int color_queue_enqueue(p_color_queue_t p_color_queue, color_t color){
    if(p_color_queue == NULL) return FAIL;

    if(FRACASSO == enqueue(p_color_queue->queue, &color, sizeof(color_t), 0)) return FAIL;
    
    return SUCCESS;
}

/*-------------------------------------------------------------------------*/
int color_queue_dequeue(p_color_queue_t p_color_queue, color_t * p_color){
    if(p_color_queue == NULL) return FAIL;

    int data_type;

    if(FRACASSO == dequeue(p_color_queue->queue, p_color, &data_type)) return FAIL;

    return SUCCESS;
}


/************************/
/*  Internal handlers  */
/***********************/