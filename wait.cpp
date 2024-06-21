#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    if (queue->front == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Queue* queue) {
    if (queue->front == 0 && queue->rear == MAX_SIZE - 1)
        return 1;
    if (queue->front == queue->rear + 1)
        return 1;
    return 0;
}

void enQueue(struct Queue* queue, int value) {
    if (isFull(queue))
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

int deQueue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
        else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return item;
    }
}

void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue))
        printf("Queue is empty\n");
    else {
        printf("Front: %d, ", queue->front);
        printf("Items in the queue: ");
        for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
            printf("%d ", queue->items[i]);
        printf("%d\n", queue->items[i]);
        printf("Rear: %d\n", queue->rear);
    }
}

int main() {
    struct Queue* queue = createQueue();

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    display(queue);

    printf("Dequeuing: %d\n", deQueue(queue));
    printf("Dequeuing: %d\n", deQueue(queue));

    display(queue);

    enQueue(queue, 6);
    display(queue);

    return 0;
}
