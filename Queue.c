#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
//
// Created by misha on 3/22/2021.
//
#define BAD_ALLOC "MEMORY ALLOCATION ERROR\n"
struct q {
    int front, rear, size;
    unsigned int capacity;
    int *array;
};

typedef struct q* Queue;

Queue createQueue(unsigned int  capacity) {
    Queue queue = (Queue) malloc(sizeof(struct q));
    if (!queue) { printf("%s", BAD_ALLOC); }
    queue->array = (int *) malloc(sizeof(int) * capacity);
    queue->rear = capacity - 1;
    queue->front = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}
int isFull(Queue q){
    return q->size == q->capacity;
}
int isEmpty(Queue q){
    return q->size == 0;
}
void enq(Queue q, int elem){
    if(isFull(q)) return;
    q->rear = ((q->rear + 1) % (q->capacity));
    q->array[q->rear] = elem;
    q->size++;
}

int deq(Queue q){
    if(isEmpty(q)) return INT_MIN;
    int ret = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return ret;
}
int front(Queue q){
    if(isEmpty(q)) return INT_MIN;
    return q->array[q->front];
}
int rear(Queue q){
    if(isEmpty(q)) return INT_MIN;
    return q->array[q->rear];
}



