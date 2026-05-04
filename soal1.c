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
    int position = 0;
    while (current != NULL) {
        if (current->data == x) {
            printf("FOUND %d\n", position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("NOT FOUND\n");
}
void printList() {
    if (head == NULL) {
        printf("LIST EMPTY\n");
        return;
    }
    Node* current = head;
    printf("LIST ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    int Q, op, x;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &op, &x);
        switch (op) {
            case 1:
                PUSH_FRONT(x);
                break;
            case 2:
                PUSH_BACK(x);
                break;
            case 3:
                DELETE(x);
                break;
            case 4:
                FIND(x);
                break;
        }
    }
    printList();
    return 0;
}
