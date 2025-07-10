#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Queue {
   int *arr;
   int front;
   int rear;
   int cap;
}Queue;
Queue *createQueue(int cap) {
   Queue *q = (Queue*)malloc(sizeof(Queue));
   q->arr = (int*)malloc(sizeof(int)*cap);
   q->front = 0;
   q->rear = -1;
   return q;
}
int isEmpty(Queue *q) {
   return q->front > q->rear;
}
int isFull(Queue *q) {
   return q->rear == q->cap - 1;
}
void enQueue(Queue *q, int x) {
   if (isFull(q)) {
      printf("\nHang doi da full\n");
      return;
   }
   q->rear++;
   q->arr[q->rear] = x;
}
int deQueue(Queue *old, Queue *nor) {
   if (isEmpty(old) && isEmpty(nor)) {
      printf("\nCa hai hang doi dang trong\n");
      return -1;
   }
   int value;
   if (isEmpty(old) && !isEmpty(nor)) {
      value = nor->arr[nor->front];
      nor->front++;
   }else {
      value = old->arr[old->front];
      old->front++;
   }
   return value;
}
void freeQueue(Queue *q) {
   free(q->arr);
   free(q);
}
int main(){
   int size;
   int normalSize = 0;
   printf("Moi nhap so luong cho hang doi: ");
   scanf("%d",&size);
   int arr[size];
   for(int i=0;i<size;i++) {
      printf("Moi nhap do tuoi cho khach hang thu %d: ",i+1);
      scanf("%d",&arr[i]);
      if (arr[i]<60) {
         normalSize++;;
      }
   }
   Queue *normalQueue = createQueue(normalSize);
   Queue *oldQueue = createQueue(size - normalSize);
   for (int i = 0; i < size; i++) {
      if (arr[i]>=60) {
         enQueue(oldQueue, arr[i]);
      }else {
         enQueue(normalQueue, arr[i]);
      }
   }
   freeQueue(oldQueue);
   freeQueue(normalQueue);
   return 0;
}
