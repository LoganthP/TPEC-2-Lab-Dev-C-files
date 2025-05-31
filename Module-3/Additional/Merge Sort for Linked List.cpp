#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* getMiddle(Node* head) {
    if (head == NULL) return head;
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next)
        return head;

    Node* middle = getMiddle(head);
    Node* rightHalf = middle->next;
    middle->next = NULL;

    Node* leftSorted = mergeSort(head);
    Node* rightSorted = mergeSort(rightHalf);

    return merge(leftSorted, rightSorted);
}

int main() {
    Node* head = NULL;

    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 8);
    insert(&head, 3);
    insert(&head, 1);

    printf("Original List: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted List:   ");
    printList(head);

    return 0;
}
