#include "llist.h"
#include "test.h"

node *remove_node(node *head, size_t position) {
    if (head != NULL) {
        if (position == 0)
            head = head->next;
        else {
            node* next = head->next;
            node* previous = head;
            int i = 0;
            while (i < position && next != NULL) {
                previous = next;
                next = next->next;
                ++i;
            }
            if (i == position)
                previous = next->next;
        }
    }
    return head;
}

int test_remove_node_at_first_position() {
    node *head = create_list(1);
    head = remove_node(append_list(head, create_list(2)), 0);
    int value = head->value;
    release_list(head);
    return !(value == 2);
}

int test_remove_node_at_non_existing_position() {
    node *head = create_list(1);
    head = insert_node(append_list(head, create_list(2)), create_list(3), 4);
    int value = head->next->value;
    node *next = head->next->next;
    release_list(head);
    return !(value == 2 && next == NULL);
}

int test_remove_node_in_null_list() {
    node *head = NULL;
    head = insert_node(head, create_list(1), 1);
    return !(head == NULL);
}

int test_remove_node_at_last_position() {
    node *head = create_list(1);
    head = insert_node(append_list(head, create_list(2)), create_list(3), 2);
    int value = head->next->next->value;
    node *next = head->next->next->next;
    release_list(head);
    return !(value == 3 && next == NULL);
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
    int test_2 = 0; //test_remove_node_at_non_existing_position();
    int test_3 = 0; //test_remove_node_in_null_list();
    int test_4 = 0; //test_remove_node_at_last_position();
    int test_5 = test_remove_node_at_second_position();
    return test_result(5, test_1, test_2, test_3, test_4, test_5);
}

