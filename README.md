# Linked Lists in C

This is a simple exercise to create linked list data structures useing the C programming language.

## Environment

- Kubuntu 18.10 - GNU/Linux
- Intel CPU - 64 bits
- GCC Version 7.3.0
- CMake 3.13.0
- NVim Version 0.2.2

## Github Repository

> [Linked List in C](https://github.com/guscastles/clinkedlist)

## Functions Available


```
void release_list(node *head);

node *create_list(int value);

node *append_list(node *head, node *new_node);

node *pop_node(node *head);

node *push_node(node *head, node *new_head);

node *insert_node(node *head, node *new_node, size_t position);
```
