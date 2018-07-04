#include <stdlib.h>
#include <stdio.h>

/**
 * A 'linked list' style QueueNode, which points to the next QueueNode
 */
struct QueueNode {
    int key;
    struct QueueNode *next;
};

/**
 * A classic Queue, that keeps track of the front and the rear nodes
 */
struct Queue {
    struct QueueNode *front, *rear;
};

/**
 * Creates a new QueueNode
 *
 * @param key
 * @return
 */
struct QueueNode *newNode(int key) {

    struct QueueNode *tmpNode = (struct QueueNode *) malloc(sizeof(struct QueueNode));

    tmpNode->key = key;
    tmpNode->next = NULL;

    return tmpNode;
}

/**
 * Creates a new Queue
 *
 * @return
 */
struct Queue *newQueue() {

    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));

    q->front = q->rear = NULL;

    return q;
}

/**
 * Adds a new QueueNode to the end of the Queue
 *
 * @param q
 * @param key
 */
void enQueue(struct Queue *q, int key) {

    struct QueueNode *tmpNode = newNode(key);

    // if queue is empty, then the new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = tmpNode;
        return;
    }

    // add the new node at the end of queue and change rear
    q->rear->next = tmpNode;
    q->rear = tmpNode;
}

/**
 * Removes a QueueNode of the front of the Queue, moves front->next to actual "front"
 *
 * @param q
 * @return
 */
struct QueueNode *deQueue(struct Queue *q) {

    // if queue is empty, return NULL.
    if (q->front == NULL) {
        return NULL;
    }

    // store previous front and move front one node ahead
    struct QueueNode *tmpNode = q->front;
    q->front = q->front->next;

    // if front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    return tmpNode;
}

/**
 * Checks whether the Queue is empty
 *
 * @param q
 * @return
 */
int isEmpty(struct Queue *q) {

    // queue is empty if there's no front or rear nodes
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    }

    return 0;
}

int main() {

    /*
     * testing:
     *
     * creates the queue
     * (empty)
     *
     * add 10 to queue
     * (not empty)
     *
     * add 20 to queue
     * (not empty)
     *
     * remove 10 from queue
     * (not empty)
     *
     * remove 20 from queue
     * (empty)
     *
     */
    struct Queue *q = newQueue();

    int r = isEmpty(q);
    printf("%i, %s \n", r, "is empty?");

    enQueue(q, 10);

    r = isEmpty(q);
    printf("%i, %s \n", r, "is empty?");

    enQueue(q, 20);

    r = isEmpty(q);
    printf("%i, %s \n", r, "is empty?");

    deQueue(q);

    r = isEmpty(q);
    printf("%i, %s \n", r, "is empty?");

    deQueue(q);

    r = isEmpty(q);
    printf("%i, %s \n", r, "is empty?");

    return 0;
}
