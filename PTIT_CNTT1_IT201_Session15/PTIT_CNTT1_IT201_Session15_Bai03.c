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
bool isEmpty(Queue *q) {
   if (q->front > q->rear) {
      printf("true");
      return true;
   }
   printf("false");
   return false;
}

int main(){
   int size;
   printf("Moi nhap so luong phan tu cho queue: ");
   scanf("%d",&size);
   Queue *queue = createQueue(size);
   int check = isEmpty(queue);
   free(queue->datas);
   free(queue);
   return 0;
}
