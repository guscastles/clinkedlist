#include <malloc.h>

struct linked_node {
    int value;
    struct linked_node *next;
};

typedef struct linked_node node;

void release_list(node *head);

node *create_node(int value, node *next);

node *append_node(node *head, node *new_node);

