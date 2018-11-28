#include "llist.h"
#include "test.h"

int test_remove_node_at_first_position() {
    node *head = create_list(1);
    head = remove_node(append_list(head, create_list(2)), 0);
    int value = head->value;
    release_list(head);
    return !(value == 2);
}

int test_remove_node_at_non_existing_position() {
    node *head = create_list(1);
    head = remove_node(append_list(head, create_list(2)), 4);
    int value = head->next->value;
    node *next = head->next->next;
    release_list(head);
    return !(value == 2 && next == NULL);
}

int test_remove_node_in_null_list() {
    node *head = NULL;
    head = remove_node(head, 4);
    return !(head == NULL);
}

int test_remove_node_at_last_position() {
    node *head = create_list(1);
    head = remove_node(append_list(append_list(head, create_list(2)), create_list(3)), 2);
    int value = head->next->value;
    node *next = head->next->next;
    release_list(head);
    return !(value == 2 && next == NULL);
}

int test_remove_node_at_second_position() {
    node *head = create_list(1);
    head = append_list(append_list(head, create_list(2)), create_list(3));
    head = remove_node(head, 1);
    node *next = head->next;
    int value = next->value;
    release_list(head);
    return !(value == 3);
}

int main() {
    int test_1 = test_remove_node_at_first_position();
    int test_2 = test_remove_node_at_non_existing_position();
    int test_3 = test_remove_node_in_null_list();
    int test_4 = test_remove_node_at_last_position();
    int test_5 = test_remove_node_at_second_position();
    return test_result(5, test_1, test_2, test_3, test_4, test_5);
}

