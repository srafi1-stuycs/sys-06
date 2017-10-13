#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
}

void print_list(struct node *start) {
    if (start == NULL) {
        printf("\n");
    } else {
        printf("%d ", &start.value);
    }
}
