#include "llist.h"

int test_pop_node() {
    node *head = create_list(1);
    head = append_list(head, create_list(2));
    head = pop_node(head);
    int result = head->value == 2 && head->next == NULL;
    release_list(head);
    return !result;
}

int main() {
    return test_pop_node();
}

