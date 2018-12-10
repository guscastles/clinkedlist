#include <stdio.h>
#include "llist.h"

void release_list(NODE head) {
    NODE *next = (NODE *)head.next;
    NODE *next_node = NULL;
    while (next != NULL) {
        next_node = next->next;
        free(next);
        next = next_node;
    }
}

NODE create_list(int value) {
    NODE new_node;
    new_node.value = value;
    new_node.next = NULL;
    return new_node;
}

NODE append_list(NODE head, NODE new_node) {
    NODE *next = head.next;
    if (next == NULL) {
        next = malloc(sizeof(NODE));
        *(next) = new_node;
        next->next = NULL;
        head.next = next;
    } else {
        NODE *current = next;
        while (next->next != NULL) {
            next = next->next;
        }
        next->next = malloc(sizeof(NODE));
        *(next->next) = new_node;
        next->next->next = NULL;
        head.next = current; 
    }
    return head;
}

TUPLE pop_node(NODE head) {
    TUPLE tuple;
    tuple.node = head;
    tuple.list = head.next;
    if (head.next != NULL)
        head.next = NULL;
    return tuple;
}

NODE push_node(NODE head, NODE new_head) {
    new_head.next = &head;
    return new_head;
}

NODE *node_at(NODE *head, size_t position) {
    NODE *next = head;
    int i = 0;
    while (i++ < position && (next = next->next) != NULL) {}
    return next;
}

NODE *insert_node(NODE *head, NODE *new_node, size_t position) {
    if (position == 0) {
        *head = push_node(*head, *new_node);
    } else if (head != NULL) {
        NODE *previous = node_at(head, position - 1);
        if (previous != NULL) {
            new_node->next = previous->next;
            previous->next = new_node;
        }
    }
    return head;
}

NODE *remove_node(NODE *head, size_t position) {
    if (head != NULL)
        if (position == 0)
            head = head->next;
        else {
            NODE* one_node_before = node_at(head, position - 1);
            if (one_node_before != NULL && one_node_before->next != NULL)
                one_node_before->next = one_node_before->next->next;
        }
    return head;
}

int list_size(NODE* head) {
    int i = 0;
    for (NODE* next = head; next != NULL; ++i, next = next->next) {}
    return i;
}
