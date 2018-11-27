#include <stdio.h>
#include "llist.h"

int main(int argc, char *argv[]) {
    node *head = create_list(1);
    for (int i = 2; i <= 10; ++i)
        head = push_node(head, create_list(i));
    node *next = head;
    while (next != NULL) {
        printf("%d ", next->value);
        next = pop_node(next);
    }
    puts("");
    return 0;
}

