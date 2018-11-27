#include "llist.h"

void release_list(node *head) {
    node *next = head;
    while (next != NULL) {
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
    if (head != NULL) {
        node *current = head;
        node *next = current->next;
        while (next != NULL) {
            current = next;
            next = next->next;
        }
        current->next = new_node;
        new_node->next = next;
    }
    return head;
}

node *pop_node(node *head) {
    if (head != NULL) {
        node *new_head = head->next;
        head->next = NULL;
        release_list(head);
        return new_head;
    }
    return head;
 }

node *push_node(node *head, node *new_head) {
    if (new_head != NULL) {
        new_head->next = head;
        return new_head;
    }
    return head;
 }

node *node_at(node *head, size_t position) {
    node *next;
    for(int i = 0, next = head; i < position && next != NULL; ++i, next = next->next) {}
    return next;
}

node *insert_node(node *head, node *new_node, size_t position) {
    if (position > 0 && head != NULL)
        if (position == 0 && new_node != NULL) {
            new_node->next = head;
            head = new_node;
        } else {
            node *previous = node_at(head, position - 1);
            node *found = previous->next;
            if (found != NULL || i == position)
                new_node->next = found;
            previous->next = new_node;
        }
    return head;
}

