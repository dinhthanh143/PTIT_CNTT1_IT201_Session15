#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Queue {
   int *data;
   int front;
   int rear;
   int cap;
} Queue;

Queue *createQueue(int size) {
   Queue *q = (Queue*) malloc(sizeof(Queue));
   q->data = (int *) malloc(sizeof(int) * size);
   q->front = 0;
   q->rear = -1;
   q->cap = size;
   return q;
}
int isFull(Queue *q) {
   return q->rear == q->cap - 1;
}
int isEmpty(Queue *q) {
   return q->front>q->rear;
}
void enqueue(Queue *q, int x) {
   if(isFull(q)) {
      return;
   }
   q->rear++;
   q->data[q->rear] = x;
}
void printQueue(Queue *q) {
   if (isEmpty(q)) {
      return;
   }
   for (int i = q->front; i <= q->rear; i++) {
      printf("%d\t", q->data[i]);
   }
}
void checkQueue(Queue *q) {
   if (isEmpty(q)) {
      return;
   }
   if (q->front == q->rear) {
      printf("\nQueue chi co mot phan tu");
      return;
   }
   for (int i = q->front+1; i <= q->rear; i++) {
      if ( q->data[i] - q->data[i-1] != 1) {
         printf("\nFalse");
         return;
      }
   }
   printf("\nTrue");
}
int main() {
   int size;
   printf("Moi nhap so luong phan tu: ");
   scanf("%d", &size);
   Queue *q = createQueue(size);
   for (int i = 0; i < size; i++) {
      printf("Moi nhap phan tu thu %d: ", i+1);
      int value;
      scanf("%d", &value);
      enqueue(q, value);
   }
   printQueue(q);
   checkQueue(q);
   free(q->data);
   free(q);
   return 0;
}
