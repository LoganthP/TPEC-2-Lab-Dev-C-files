#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
// Push element into the stack
void push(int data) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

// Pop element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Get middle element of the stack
int findMiddle() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    int midIndex = top / 2;  // Integer division gives the lower middle index for even-sized stacks
    return stack[midIndex];
}
// Display stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
// Main function
int main() {
    int n, element;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX);
        return 1;  // Exit the program with an error code
    }
    printf("Enter elements: ");int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &element);
        push(element);
    }
    printf("Stack elements are: ");
    display();
    int midElement = findMiddle();
    if (midElement != -1) {
        printf("Middle element is: %d\n", midElement);
    }
    return 0;
}
