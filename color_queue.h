/*************************************************************
 * Color queue model developed in the context
 * of the PAA Discipline
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAIL
#define FAIL 1
#endif

typedef struct color_queue_t *p_color_queue_t, **pp_color_queue_t;


/**********************/
/* Creation operation */
/**********************/
int color_queue_init(pp_color_queue_t pp_color_queue, int queue_size);


/*************************/
/* Destruction operation */
/*************************/
int color_queue_destroy(pp_color_queue_t pp_color_queue);


/*********************/
/* Access operations */
/*********************/


/***************************/
/* Manipulation operations */
/***************************/
int color_queue_enqueue(p_color_queue_t p_color_queue, color_t color);
int color_queue_dequeue(p_color_queue_t p_color_queue, color_t * p_color);

