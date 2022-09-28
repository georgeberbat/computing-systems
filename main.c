/* Doubly Linked List implementation */
#include<stdio.h>
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Coins.h"

void demo_double_linked_list(){
    printf("DEMO DOUBLY LINKED LIST: \n");

    LinkedList * list = create_list();
    insert_last(list, 45);
    insert_first(list, 46);
    Node* head = list->head;
    insert_after(list, head, 32);
    insert_before(list, head, 42);
    show(head);
    print(list);
    remove_node(head);
    remove_head(list);
    remove_tail(list);
    print(list);
}

void demo_stack() {
    printf("\n\nDEMO STACK: \n");

    Stack * stack = create_stack();
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    print_stack(stack);
    pop(stack);
    print_stack(stack);
    pop(stack);
    print_stack(stack);
    pop(stack);
    print_stack(stack);
    pop(stack);
    print_stack(stack);
    pop(stack);
}

void demo_queue(){
    printf("\n\nDEMO QUEUE: \n");

    printf("Enqueuing: \n");
    Queue * queue = get_queue();
    for (int i = 0; i < 5; ++i)
    {
        queue_push(queue, i);
        print_queue(queue);
        printf("\n");
    }
    printf("Dequeuing: \n");
    for (int i = 0; i < 5; ++i)
    {
        queue_pop(queue);
        print_queue(queue);
        printf("\n");
    }
}

int main() {
    demo_double_linked_list();
    demo_stack();
    demo_queue();
    solve_coins(54);
}

