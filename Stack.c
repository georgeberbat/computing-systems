#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

//
// Created by invar on 28.09.2022.
//
Stack * create_stack() {
    Stack * stack;
    stack = malloc(sizeof(stack));
    stack -> head = NULL;
    return stack;
}

unsigned is_empty(Stack * stack) {
    return (stack -> head == NULL);
}

void push(Stack * stack, int key) {
    SinglyNode * node;
    node = malloc(sizeof(SinglyNode));
    node -> key = key;
    if(!is_empty(stack)){
        stack -> head -> next = node;
    }
    stack -> head = node;
}

int pop(Stack * stack){
    if(is_empty(stack)){
        return INT_MIN;
    }

    int result = stack -> head -> key;

    return result;
}

