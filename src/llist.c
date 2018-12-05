#include <stdio.h>
#include "llist.h"

void release_list(node *head) {
    if (head != NULL) {
        node *next = head;
        while (next->next != NULL) {
            free(next);
            next = next->next;
        }
        free(next);
    }
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
        node *next = head->next;
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
    node *new_head = head;
    if (head != NULL) {
        new_head = head->next;
        head->next = NULL;
        release_list(head);
    }
    return new_head;
}

node *push_node(node *head, node *new_head) {
    node *hd = head;
    node *nhd = new_head;
    if (nhd != NULL) {
        nhd->next = head;
        hd = new_head;
    }
    return hd;
}

node *node_at(node *head, size_t position) {
    node *next = head;
    int i = 0;
    while (i++ < position && (next = next->next) != NULL) {}
    return next;
}

node *insert_node(node *head, node *new_node, size_t position) {
    if (position == 0) {
        head = push_node(head, new_node);
    } else if (head != NULL) {
        node *previous = node_at(head, position - 1);
        if (previous != NULL) {
            new_node->next = previous->next;
            previous->next = new_node;
        }
    }
    return head;
}

node *remove_node(node *head, size_t position) {
    if (head != NULL)
        if (position == 0)
            head = head->next;
        else {
            node* one_node_before = node_at(head, position - 1);
            if (one_node_before != NULL && one_node_before->next != NULL)
                one_node_before->next = one_node_before->next->next;
        }
    return head;
}

int list_size(node* head) {
    int i = 0;
    for (node* next = head; next != NULL; ++i, next = next->next) {}
    return i;
}
