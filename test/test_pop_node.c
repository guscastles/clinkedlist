#include "llist.h"

int test_pop_node() {
    NODE head = create_list(1);
    head = append_list(head, create_list(2));
    TUPLE pair = pop_node(head);
    int result = pair.node.value == 1 && pair.list->value == 2;
    release_list(head);
    return !result;
}

int main() {
    return test_pop_node();
}

