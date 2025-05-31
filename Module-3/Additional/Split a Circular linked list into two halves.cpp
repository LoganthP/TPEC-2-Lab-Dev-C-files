#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void splitCircularList(struct Node* head, struct Node** head1, struct Node** head2) {
    if (head == NULL) return;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head) {
        fast = fast->next;
    }

    *head1 = head;

    if (head->next != head) {
        *head2 = slow->next;
    }

    slow->next = *head1;
    fast->next = *head2;
}

void printList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    printf("Original Circular Linked List: ");
    printList(head);

    splitCircularList(head, &head1, &head2);

    printf("First Half: ");
    printList(head1);

    printf("Second Half: ");
    printList(head2);

    return 0;
}
