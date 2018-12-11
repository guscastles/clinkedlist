#include <stdio.h>
#include "test.h"
#include "llist.h"

int test_insert_node() {
    NODE head = create_list(1);
    head = insert_node(append_list(head, create_list(2)), create_list(3), 1);
    int value = head.next->next->value;
    release_list(head);
    return !(value == 3);
}

int test_insert_node_at_non_existing_position() {
    NODE head = create_list(1);
    head = insert_node(append_list(head, create_list(2)), create_list(3), 4);
    int value = head.next->value;
    NODE *next = head.next->next;
    release_list(head);
    return !(value == 2 && next == NULL);
}

int test_insert_node_in_null_list() {
    NODE head;
    head = insert_node(head, create_list(1), 1);
    return !(head.next == NULL);
}

int test_insert_node_at_last_position() {
    NODE head = create_list(1);
    head = insert_node(insert_node(head, create_list(2), 1), create_list(3), 2);
    int value = head.next->next->value;
    NODE *next = head.next->next->next;
    release_list(head);
    return !(value == 3 && next == NULL);
}

int test_insert_node_at_first_position() {
    NODE head = create_list(1);
    NODE initial_head = head;
    head = insert_node(head, create_list(2), 0);
    int value = head.value;
    int initial_value = head.next->value;
    release_list(head);
    return !(value == 2 && initial_value == initial_head.value);
}

int main() {
    int test_1 = test_insert_node();
    int test_2 = test_insert_node_at_non_existing_position();
    int test_3 = test_insert_node_in_null_list();
    int test_4 = test_insert_node_at_last_position();
    int test_5 = test_insert_node_at_first_position();
    return test_result(5, test_1, test_2, test_3, test_4, test_5);
}

