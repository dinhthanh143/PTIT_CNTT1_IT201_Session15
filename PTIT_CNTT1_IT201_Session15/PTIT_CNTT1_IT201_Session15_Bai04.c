#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Queue {
    int *datas;
    int front;
    int rear;
    int size;
}Queue;
Queue *createQueue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (q==NULL) {
        return NULL;
    }
    q->datas = (int *)malloc(sizeof(int)*size);
    if (q->datas==NULL) {
        free(q);
        return NULL;
    }
    q->front = 0;
    q->rear = -1;
    q->size = size;
    return q;
}
int isEmpty(Queue *q) {
    return q->front >q->rear;
}
int isFull(Queue *q) {
    return q->rear == q->size -1;
}
void enQueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->datas[q->rear] = value;
}
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i<=q->rear; i++) {
        printf("%d \t",q->datas[i]);
    }
}
int main(){
    int size;
    printf("Moi nhap so luong phan tu cho queue: ");
    scanf("%d",&size);
    Queue *queue = createQueue(size);
    for (int i=0;i<size;i++) {
        enQueue(queue,i+1);
    }
    printQueue(queue);
    free(queue->datas);
    free(queue);
    return 0;
}
