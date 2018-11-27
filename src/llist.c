#include "llist.h"

void release_list(node *head) {
    node *next;
    while ((next = head) == NULL) {
        next = next->next;
        free(next);
    }
    head = NULL;
}

node *create_list(int value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

node *append_list(node *head, node *new_node) {
    node *current = head;
    node *next = current->next;
    while (next != NULL) {
        current = next;
        next = next->next;
    }
    current->next = new_node;
    new_node->next = next;
    return head;
}

node *pop_node(node *head) {
    node *new_head = head->next;
    head->next = NULL;
    release_list(head);
    return new_head;
 }

node *push_node(node *head, node *new_head) {
    new_head->next = head; 
    return new_head;
 }

