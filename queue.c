#include <stdio.h>
#include<stdlib.h>
#ifdef _WIN32
#include<conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif
#define CAPACITY 5

struct Node {
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* create_node(int);
void enqueue(int);
void dequeue();
void peek_front();
void peek_rear();
int isFull();

int main() {
	int data;
	while(1) {
		printf("[1] Enqueue\n[2] Dequeue\n[3] Peek Front\n[4] Peek Rear\n[5] Exit\nEnter choice : ");
		int choice;
		scanf("%d" , &choice);
		clrscr();
		switch(choice) {
			case 1 : if(isFull() == 1) {
					 puts("Queue Overflow !\n");
					 break;
				 }
				 printf("Enter data : ");
				 scanf("%d" , &data);
				 enqueue(data);
				 puts("Data enqueued !\n");
				 break;

			case 2 : if(front == NULL) {
					 puts("Queue Underflow !\n");
					 break;
				 }
				 dequeue();
				 puts("Data dequeued !\n");
				 break;

			case 3 : peek_front();
				 break;

			case 4 : peek_rear();
				 break;

			case 5 : puts("Exitting ...");
				 exit(0);

			default : puts("Wrong choice !\n");
		}
	}
}

struct Node* create_node(int data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->next = NULL;
	new_node->data = data;
	return new_node;
}

void enqueue(int data) {
	struct Node* new_node = create_node(data);
	rear = new_node;
	if(front == NULL) {
		front = new_node;
	}else{
		struct Node* current = front;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
}

void dequeue() {
	struct Node* temp = front;
	front = front->next;
	free(temp);
	if(front == NULL) {
		rear = NULL;
	}	
}

void peek_front() {
	if(front == NULL) {
		puts("Queue Underflow !\n");
		return;
	}
	printf("Front Element = %d\n\n" , front->data);
}

void peek_rear() {
	if(rear == NULL) {
		puts("Queue Underflow !\n");
		return;
	}
	printf("Rear Element = %d\n\n" , rear->data);
}

int isFull() {
	int count = 1;
	struct Node* current = front;
	while(current != rear) {
		current = current->next;
		count++;
	}
	return count == CAPACITY;
}
