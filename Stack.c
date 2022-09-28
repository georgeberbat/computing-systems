#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

//
// Created by invar on 28.09.2022.
//
Stack * create_stack() {
    Stack * stack;
    stack = malloc(sizeof(Stack));
    stack -> head = NULL;
    return stack;
}

unsigned is_empty_stack(Stack * stack) {
    return (stack -> head == NULL);
}

void push(Stack * stack, int key) {
    SinglyNode * node;
    node = malloc(sizeof(SinglyNode));
    node -> key = key;

    node -> prev = stack -> head;
    stack -> head = node;
}

int pop(Stack * stack){
    if(is_empty_stack(stack)){
        return INT_MIN;
    }

    SinglyNode * result_node = stack -> head;

    if(stack -> head -> prev) {
        stack -> head = stack -> head -> prev;
    }

    int result = result_node -> key;
    free(result_node);

    return result;
}

void print_stack(Stack * stack) {
    if(stack -> head == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    SinglyNode * cur = stack -> head;
    int count;
    count=0;
    while(cur!=NULL)
    {
        printf("%d->",cur -> key);
        count++;
        cur= cur -> prev;
    }
    printf("NULL\n");
    printf("number of nodes %d\n",count);
}