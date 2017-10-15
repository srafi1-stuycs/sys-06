#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void print_list(struct node *start) {
    if (!start) { // if you get a null pointer
        printf("\n"); // end of list
    } else {
        printf("%d ", start->value);
        print_list(start->next); // print rest of list
    }
}

struct node* insert_front(struct node *old_start, int val) {
    struct node *new_start = malloc(sizeof(struct node));
    new_start->value = val;
    new_start->next = old_start;
    return new_start;
}

struct node* free_list(struct node *start) {
    if (start) {
        free(start);
        return free_list(start->next);
    } else {
        return start;
    }
}

int main() {
    printf("Starting list and inserting 3...\n");
    struct node* list = insert_front(NULL, 3);
    printf("inserting 2...\n");
    list = insert_front(list, 2);
    printf("inserting 1...\n");
    list = insert_front(list, 1);
    printf("Here's the list:\n");
    print_list(list);
    printf("Freeing list...\n");
    list = free_list(list);
    printf("Printing list from new pointer...\n");
    print_list(list);
    return 0;
}
