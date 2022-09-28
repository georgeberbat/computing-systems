//
// Created by invar on 28.09.2022.
//
#include <malloc.h>
#include <stdio.h>
#include "DoublyLinkedList.h"

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H
typedef struct Queue {
    struct Node *front;
    struct Node *rear;
    int size;
} Queue;

Node * get_node(int data, Node *prev);

Queue * get_queue();

void queue_push(Queue * ref, int data);

int is_queue_empty(Queue * ref);

int peek(Queue * ref);

int queue_size(Queue * ref);

int queue_pop(Queue * ref);

void print_queue(Queue * ref);

#endif //UNTITLED_QUEUE_H
