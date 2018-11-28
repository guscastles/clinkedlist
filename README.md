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

node *node_at(node *head, size_t position);

node *insert_node(node *head, node *new_node, size_t position);

node *remove_node(node *head, size_t position);
```

## Abstract

This is on of the simplest data structure algorithms to start learning, hence the choice in my comeback to the C programming language. I tried to apply all the concepts of clean code and test-driven development, using the very simple mechanism provided by the *ctest* application. Also I used the complexity *application* to verify the maintainability of the code.

This is the output for the *llist.c* file:

> $ complexity  -t 1 --histogram --scores src/llist.c

```
Complexity Scores
Score | ln-ct | nc-lns| file-name(line): proc-name
    1       3       3   ../src/llist.c(50): node_at
    1       4       4   ../src/llist.c(11): create_list
    1       5       5   ../src/llist.c(42): push_node
    1       6       6   ../src/llist.c(2): release_list
    1       7       7   ../src/llist.c(32): pop_node
    2      10      10   ../src/llist.c(56): insert_node
    2      11      11   ../src/llist.c(18): append_list
    4      17      17   ../src/llist.c(69): remove_node

Complexity Histogram
Score-Range  Lin-Ct
    0-9          63 ************************************************************

Scored procedure ct:        8
Non-comment line ct:       63
Average line score:         2
25%-ile score:              1 (75% in higher score procs)
50%-ile score:              2 (half in higher score procs)
75%-ile score:              2 (25% in higher score procs)
Highest score:              4 (remove_node() in ../src/llist.c)
```

I am not totally happy with the *remove_node* function, but it is a living entity, as any software endeavour.

## Contribute and Join the Fun

Any contributions are welcome, since this is a learning journey. Fork it on github and let me know. Cheers!

## The Author

Please find me on [LinkedIn][1].

[1]: https//linkedin.com/in/guscastles

