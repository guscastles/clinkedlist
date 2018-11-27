#include "llist.h"

int test_create_node() {
    node *head = create_node(1);
    int result = head->value == 1 && head->next == NULL;
    release_list(head);
    return !result;
}

int main() {
    return test_create_node();
}

