#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void PUSH_BACK(int x){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = NULL;
    if (tail == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}
void PUSH_FRONT(int x){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = head;
    head = new_node;
    if (tail == NULL) {
        tail = new_node;
    }
}
void DELETE(int x) {
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == x) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            if (current == tail) {
                tail = prev;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
void FIND(int x ){
    Node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            printf("Data %d ditemukan\n", x);
            return;
        }
        current = current->next;
    }
    printf("Data %d tidak ditemukan\n", x);
}
void LIST_EMPTY() {
    if (head == NULL) {
        printf("LIST EMPTY\n");
    }
}
int main() {
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        char op[10];
        int x;
        scanf("%s %d", op, &x);
        if (strcmp(op, "PUSH_BACK") == 0) {
            PUSH_BACK(x);
        } else if (strcmp(op, "PUSH_FRONT") == 0) {
            PUSH_FRONT(x);
        } else if (strcmp(op, "DELETE") == 0) {
            DELETE(x);
        } else if (strcmp(op, "FIND") == 0) {
            FIND(x);
        }
    }
    LIST_EMPTY();
    return 0;
}

