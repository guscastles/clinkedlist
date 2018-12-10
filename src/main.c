#include <stdio.h>
#include "llist.h"

int main(int argc, char *argv[]) {
    NODE *head = create_list(1);
    for (int i = 2; i <= 10; ++i)
        head = append_list(head, create_list(i));
    NODE *next = remove_node(head, 3);
    next = insert_node(next, create_list(20), 2);
    next = remove_node(next, 9);
    next = remove_node(next, 10);
    next = remove_node(next, 0);
    printf("Node at position %d is %d\n", 3, node_at(next, 3)->value);
    while (next != NULL) {
        printf("%d ", next->value);
        next = pop_node(next);
    }
    puts("");
    release_list(next);
    return 0;
}

