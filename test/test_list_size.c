#include <stdio.h>
#include <assert.h>
#include "llist.h"

void test_list_size() {
    NODE head = create_list(1);
    head = append_list(head, create_list(2));
    int size = list_size(head);
    release_list(head);
    assert(size == 2);
}

int main() {
    test_list_size();
    return 0;
}

