#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertFront(struct node** head, int val) {
    struct node* newNode = createNode(val);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAfter(struct node* prev_node, int val) {
    if (prev_node == NULL) return;

    struct node* newNode = createNode(val);
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void deleteNode(struct node** head, struct node* del) {
    if (*head == NULL || del == NULL) return;

    if (*head == del) {
        *head = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
}

void display(struct node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    insertFront(&head, 10);
    insertFront(&head, 20);
    insertFront(&head, 30);

    printf("Initial List: ");
    display(head);

    printf("Inserting 25 after 20...\n");
    insertAfter(head->next, 25);
    display(head);

    printf("Deleting 10 (the tail)...\n");
    struct node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    deleteNode(&head, temp);
    display(head);

    return 0;
}