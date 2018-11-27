#include "llist.h"

int test_pop_node() {
    node *head = create_node(1);
    head = append_node(head, create_node(2));
    head = pop_node(head);
    int result = head->value == 2 && head->next == NULL;
    release_list(head);
    return !result;
}

int main() {
    return test_pop_node();
}

