//
// Created by invar on 28.09.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"


LinkedList * create_list() {
    LinkedList * linkedList;
    linkedList = malloc(sizeof(LinkedList));
    linkedList -> head = NULL;
    linkedList -> tail = NULL;
    return linkedList;
}

unsigned is_empty(LinkedList * linkedList) {
    return (linkedList -> head == NULL) && (linkedList -> tail == NULL);
}

void insert_first(LinkedList * linkedList, int key) {
    Node * node;
    node = malloc(sizeof(Node));
    node -> key = key;
    node -> next = linkedList -> head;
    node -> prev = NULL;
    if (is_empty(linkedList))
        linkedList -> tail = node;
    else
        linkedList -> head -> prev = node;
    linkedList -> head = node;
}

void insert_last(LinkedList * linkedList, int key) {
    Node * node;
    node = malloc(sizeof(Node));
    node -> key = key;
    node -> next = NULL;
    if (is_empty(linkedList)) {
        node -> prev = NULL;
        linkedList -> head = node;
        linkedList -> tail = node;
    } else {
        node -> prev = linkedList -> tail;
        linkedList -> tail -> next = node;
        linkedList -> tail = node;
    }


}

void insert_after(LinkedList * linkedList, Node * node, int key) {
    Node * temp_node;
    temp_node = malloc(sizeof(Node));
    temp_node -> key = key;
    temp_node -> next = node -> next;
    if (temp_node -> next != NULL)
        node -> next -> prev = temp_node;

    node -> next = temp_node;
    temp_node -> prev = node;
    if (temp_node -> next == NULL)
        linkedList -> tail = temp_node;
}

void insert_before(LinkedList * linkedList, Node * node, int key) {
    Node * temp_nd;
    temp_nd = malloc(sizeof(Node));
    temp_nd -> key = key;
    temp_nd -> prev = node -> prev;
    if (temp_nd -> prev != NULL)
        node -> prev -> next = temp_nd;
    node -> prev = temp_nd;
    temp_nd -> next = node;

    if (temp_nd -> prev == NULL)
        linkedList -> head = temp_nd;
}

void show(Node * node) {
    printf("%d -- ", node -> key);
}

void remove_node(Node * node) {
    if (node -> next != NULL)
        node -> next -> prev = node -> prev;
    if (node -> prev != NULL)
        node -> prev -> next = node -> next;
    free(node);
}

void remove_head(LinkedList * linkedList) {
    Node * nd;
    nd = linkedList -> head;
    linkedList -> head = nd -> next;
    free(nd);
    if (linkedList -> head == NULL)
        linkedList -> tail = NULL;
    else
        linkedList -> head -> prev = NULL;
}

void remove_tail(LinkedList * linkedList) {
    Node * node;
    if (linkedList -> head == linkedList -> tail)
        remove_head(linkedList);
    else {
        node = linkedList -> head;
        while(node ->next != linkedList -> tail)
            node = node -> next;
        node -> next = NULL;
        free(linkedList -> tail);
        linkedList -> tail = node;
    }
}

void print(LinkedList * linkedList) {
    printf("\n");
    Node * temp = linkedList -> head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ",temp -> key);
        temp = temp -> next;
    }
    printf("\n");
}