#include <assert.h>
#include "llist.h"

int test_push_node() {
    NODE head = create_list(3);
    head = append_list(head, create_list(2));
    NODE new_head = push_node(head, create_list(1));
    assert(new_head.value == 1);
    assert(new_head.next->next->value == 2);
    release_list(new_head);
    return 0;
}

int main() {
    return test_push_node();
}

