/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>
#include "DoublyLinkedList.h"

void demo_double_linked_list(){
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

int main() {
    demo_double_linked_list();
}

