#include <malloc.h>

struct linked_list_node {
    int value;
    struct linked_list_node *next;
};

typedef struct linked_list_node node;

void release_list(node *head);

node *create_list(int value);

node *append_list(node *head, node *new_node);

node *pop_node(node *head);

node *push_node(node *head, node *new_head);

node *node_at(node *head, size_t position);

node *insert_node(node *head, node *new_node, size_t position);

node *remove_node(node *head, size_t position);

int list_size(node *head);

