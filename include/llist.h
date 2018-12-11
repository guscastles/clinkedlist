#include <malloc.h>

struct linked_list_node {
    int value;
    struct linked_list_node *next;
};

typedef struct linked_list_node NODE;

struct tuple {
    NODE node;
    NODE *list;
};

typedef struct tuple TUPLE;

void release_list(NODE head);

NODE create_list(int value);

NODE append_list(NODE head, NODE new_node);

TUPLE pop_node(NODE head);

NODE push_node(NODE head, NODE new_head);

NODE *node_at(NODE *head, size_t position);

NODE insert_node(NODE head, NODE new_node, size_t position);

NODE remove_node(NODE head, size_t position);

int list_size(NODE head);

