#include <stdio.h>
#include "llist.h"

int test_insert_node() {
    node *head = create_list(1);
    head = insert_node(append_list(head, create_list(2)), create_list(3), 1);
    release_list(head);
    return !(head->next->value == 3);
}

int main() {
    return test_insert_node();
}

