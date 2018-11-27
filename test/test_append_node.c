#include <stdio.h>
#include "llist.h"

int test_append_node() {
    node *head = create_node(1);
    head = append_node(head, create_node(2));
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
    return test_append_node();
}

