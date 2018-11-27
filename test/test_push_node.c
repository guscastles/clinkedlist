#include "llist.h"

int test_push_node() {
    node *head = create_node(1);
    head = append_node(head, create_node(2));
    head = push_node(head, create_node(3));
    int result = head->value == 3 && head->next->value == 1;
    release_list(head);
    return !result;
}

int main() {
    return test_push_node();
}

