//
// Created by invar on 28.09.2022.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

struct SinglyNode {
    int key;
    struct SinglyNode * prev;
};

struct Stack {
    struct SinglyNode * head;
};

typedef struct SinglyNode SinglyNode;
typedef struct Stack Stack;

Stack * create_stack(void);
unsigned is_empty_stack(Stack *);
void push(Stack *, int);
int pop(Stack *);
void print_stack(Stack *);

#endif //UNTITLED_STACK_H
