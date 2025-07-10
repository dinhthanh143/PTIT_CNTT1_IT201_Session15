#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
typedef struct Queue {
   char customers[MAX][31];
   int front;
   int rear;
   int cap;
}Queue;

Queue *createQueue() {
   Queue *q = (Queue *) malloc(sizeof(Queue));
   q->front = 0;
   q->rear = -1;
   q->cap = MAX;
   return q;
}
int isEmpty(Queue *q) {
   return q->front > q->rear;
}
int isFull(Queue *q) {
   return q->rear == q->cap-1;
}
void enQueue(Queue *q, char customer[]) {
   if (isFull(q)) {
      printf("\nHang doi da day!\n");
      return;
   }
   q->rear++;
   strcpy(q->customers[q->rear],customer);
}
void deQueue(Queue *q) {
   if (isEmpty(q)) {
      printf("\nHang doi trong!\n");
      return;
   }
   printf("\nDa phuc vu %s\n", q->customers[q->front]);
   q->front++;
}
void printMenu() {
   printf("\tMENU\t");
   printf("\n1. Them khach hang");
   printf("\n2. Phuc vu khach hang");
   printf("\n3. Xem hang doi");
   printf("\n4. Thoat");
   printf("\n===================\nLua chon cua ban:");
}
void printQueue(Queue *q) {
   if(isEmpty(q)) {
      printf("\nHang doi rong\n");
      return;
   }
   printf("\nQUEUE:\n");
   for(int i = q->front; i <= q->rear; i++) {
      printf("%s\n", q->customers[i]);
   }
}
int main(){
   Queue *queue = createQueue();
   int choice;
   while (choice != 4) {
      printMenu();
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            getchar();
            char name[31];
            printf("\nMoi nhap ten khach hang:");
            fgets(name, 31, stdin);
            name[strcspn(name,"\n")] = 0;
            enQueue(queue, name);
            break;
         case 2:
            deQueue(queue);
            break;
         case 3:
            printQueue(queue);
            break;
         case 4:
            break;
         default:
            printf("\nLua chon khong hop le\n");
      }
   }
   free(queue);
   return 0;
}
