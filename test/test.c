#include <stdio.h>
#include <assert.h>
#include "llist.h"

int test_create_node() {
    node *next = create_node(2, NULL);
    node *head = create_node(1, next);
    int result = head->next->value == 2;
    release_list(head);
    return !result;
}

int test_append_node() {
    node *head = create_node(1, NULL);
    head = append_node(head, create_node(2, NULL));
    node *next = head->next;
    int sum = head->value;
    while (next != NULL) {
        printf("%d ", next->value);
        sum += next->value;
        next = next->next;
    }
    release_list(head);
    return !(sum == 3);
}

int main() {
    int res_create_node = test_create_node();
    int res_append_node = test_append_node();
    return res_create_node && res_append_node;
}

