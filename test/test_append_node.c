#include <stdio.h>
#include "llist.h"

int test_append_list() {
    NODE head = create_list(1);
    head = append_list(append_list(head, create_list(2)), create_list(3));
    NODE *next = head.next;
    int sum = head.value;
    while (next != NULL) {
        printf("%d ", next->value);
        sum += next->value;
        next = next->next;
    }
    release_list(head);
    return !(sum == 6);
}

int main() {
    return test_append_list();
}

