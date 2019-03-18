#include <stdio.h>
#include <stdlib.h>

// Linked list node structure for a linked list of integers
typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
} node_t;

void add_val(node_t *node, int val);
void print_ll(node_t *node);

// Print all values in a linked list starting from given node
void print_ll (node_t *node) {
    printf("Start of List\n");
    while(node != NULL) {
        if(node->prev==NULL) {
            // No previous node = First node
            if(node->next==NULL) {
                // No previous or next node = Only node
                printf("The only value is: %d\n", node->val);
            } else {
                // First node with additional nodes
                printf("The first value is: %d, The next value is: %d\n", node->val, node->next->val);
            }
        } else {
            // Previous node exists
            if(node->next==NULL) {
                // Previous node exists with no next node = Final node
                printf("Final value: %d, Previous value: %d\n", node->val, node->prev->val);
            } else {
                // Previous node and next node exists = Center node
                printf("Current value: %d, Previous value: %d, Next value: %d\n", node->val, node->prev->val, node->next->val);
            }
        }



        node = node->next;
    }
    printf("End of List\n");
}

// Adds a passed value to the end of a linked list
void add_val(node_t *node, int val) {
    // Find last node
    while (node->next != NULL) {
        node = node->next;
    }
    // Add passed value
    node->next = malloc(sizeof(node_t));
    node->next->val = val;
    node->next->prev = node;
    node->next->next = NULL;

}

int main() {

    // Initialize first node
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = NULL;
    head->prev = NULL;

    // Create a new linked list an initialize 1 to 10
    for(int i = 1; i < 10; i++) {
        int to_add = i+1;
        add_val(head, to_add);
    }

    // Print linked list
    print_ll(head);

    return 0;
}