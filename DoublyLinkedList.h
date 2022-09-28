//
// Created by invar on 28.09.2022.
//

#ifndef UNTITLED_DOUBLYLINKEDLIST_H
#define UNTITLED_DOUBLYLINKEDLIST_H
//1. Реализовать двусвязный список
// Node of a doubly linked list.
struct Node {
    int key;
    struct Node * next;
    struct Node * prev;
};

struct LinkedList {
    struct Node * head;
    struct Node * tail;
};

typedef struct Node Node;
typedef struct LinkedList LinkedList;

// Function Prototype or method on linked list.
LinkedList * create_list(void); // Initiate a linked list.
unsigned is_empty(LinkedList *); // Check if a linked list is empty or no.
void insert_first(LinkedList *, int); // Add a node in the beginning.
void insert_last(LinkedList *, int); // Add a node in the end.
void insert_after(LinkedList *, Node *, int key); // Add a node after a given node.
void insert_before(LinkedList *, Node *, int key); // Add a node before a given node.
void show(Node *); // Higher order function to be used in traverse: show node's key.
void remove_node(Node *); // Remove Node from the list.
void remove_head(LinkedList *); // Remove a node from the beginning.
void remove_tail(LinkedList *); // Remove
void print(LinkedList *);// a node from the end.
#endif //UNTITLED_DOUBLYLINKEDLIST_H
