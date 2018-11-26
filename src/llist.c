#include "llist.h"

void release_list(node *head) {
    node *next;
    while ((next = head) == NULL) {
        next = next->next;
        free(next);
    }
    head = NULL;
}

node *create_node(int value, node *next) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = next;
    return new_node;
}

node *append_node(node *head, node *new_node) {
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

