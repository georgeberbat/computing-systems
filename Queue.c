//
// Created by invar on 28.09.2022.
//

#include <malloc.h>
#include "DoublyLinkedList.h"
#include "Queue.h"

Node * get_node(int data, Node *prev) {
    Node *ref = (Node *) malloc(sizeof(Node));
    if (ref == NULL) {
        return NULL;
    }
    ref->key = data;
    ref->next = NULL;
    ref->prev = prev;
    return ref;
}

Queue * get_queue() {
    Queue *ref = (Queue *) malloc(sizeof(Queue));
    if (ref == NULL) {
        return NULL;
    }
    ref->front = NULL;
    ref->rear = NULL;
    return ref;
}

void queue_push(Queue *ref, int data) {
    Node *node = get_node(data, ref->rear);
    if (ref->front == NULL) {
        ref->front = node;
        ref->size = 1;
    } else {
        ref->rear->next = node;
        ref->size = ref->size + 1;
    }
    ref->rear = node;
}

int is_queue_empty(Queue *ref) {
    if (ref->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

int peek(Queue * ref) {
    if (is_queue_empty(ref) == 1) {
        printf("\n Empty Queue");
        // When stack is empty
        return -1;
    } else {
        return ref->front->key;
    }
}

int queue_size(Queue *ref) {
    return ref -> size;
}

int queue_pop(Queue *ref) {
    if (is_queue_empty(ref) == 1) {
        return -1;
    } else {
        int data = peek(ref);
        Node *temp = ref->front;
        if (ref->front == ref->rear) {
            ref->rear = NULL;
            ref->front = NULL;
        } else {
            ref->front = ref->front->next;
            ref->front->prev = NULL;
        }
        ref->size--;
        return data;
    }
}

void print_queue(Queue *ref) {
    Node *node = ref->front;
    printf("\n Queue Element\n");
    while (node != NULL) {
        printf(" %d", node->key);
        node = node->next;
    }
    printf("\n");
}