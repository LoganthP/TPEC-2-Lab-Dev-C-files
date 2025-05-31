#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

void enqueue(Queue* queue, int item) {
    push(queue->stack1, item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i;
    for (i = 0; i <= queue->stack2->top; i++) {
        printf("%d ", queue->stack2->array[i]);
    }
    for (i = queue->stack1->top; i >= 0; i--) {
        printf("%d ", queue->stack1->array[i]);
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue(100);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Dequeued item is %d\n", dequeue(queue));
    displayQueue(queue);
    return 0;
}
