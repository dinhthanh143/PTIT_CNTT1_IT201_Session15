#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
typedef struct Customer {
   int age;
   char name[30];
}Customer;
typedef struct Queue {
   Customer *arr;
   int front;
   int rear;
   int cap;
}Queue;
Queue *createQueue(int cap) {
   Queue *q = (Queue*)malloc(sizeof(Queue));
   q->arr = (Customer*)malloc(sizeof(Customer)*cap);
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
void enQueue(Queue *q, int x, char name[]) {
   if (isFull(q)) {
      printf("\nHang doi da full\n");
      return;
   }
   q->rear++;
   q->arr[q->rear].age = x;
   strcpy(q->arr[q->rear].name,name);
}
void deQueue(Queue *old, Queue *nor) {
   if (isEmpty(old) && isEmpty(nor)) {
      printf("\nCa hai hang doi dang trong\n");
      return;
   }
   int value;
   if (isEmpty(old) && !isEmpty(nor)) {
      value = nor->arr[nor->front].age;
      printf("\nDa phuc vu khac hang %s, %d tuoi", nor->arr[nor->front].name,value);
      nor->front++;
   }else {
      value = old->arr[old->front].age;
      printf("\nDa phuc vu khac hang %s, %d tuoi", old->arr[old->front].name,value);
      old->front++;
   }
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
   char name[MAX][30];
   for(int i=0;i<size;i++) {
      printf("Nhap ten cho khac hang thu %d: ",i+1);
      fgets(name[i],30,stdin);
      name[i][strcspn(name[i],"\n")] = 0;
      printf("Moi nhap do tuoi cho khach hang thu %d: ",i+1);
      scanf("%d",&arr[i]);
      getchar();
      if (arr[i]<60) {
         normalSize++;;
      }
   }
   Queue *normalQueue = createQueue(normalSize);
   Queue *oldQueue = createQueue(size - normalSize);
   for (int i = 0; i < size; i++) {
      if (arr[i]>=60) {
         enQueue(oldQueue, arr[i],name[i]);
      }else {
         enQueue(normalQueue, arr[i],name[i]);
      }
   }
   freeQueue(oldQueue);
   freeQueue(normalQueue);
   return 0;
}
