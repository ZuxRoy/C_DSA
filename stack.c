#include <stdio.h>
#include<stdlib.h>
#ifdef _WIN32
#include<conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif
#define CAPACITY 5

struct Node{
	int data;
	struct Node* next;
};

struct Node* top = NULL;

struct Node* create_node(int);
void push(int);
void pop();
void peek();
int isFull();

int main() {
	int data;
	while(1) {
		printf("[1] Push\n[2] Pop\n[3] Peek\n[4] Exit\nEnter choice : ");
		int choice;
		scanf("%d" , &choice);
		clrscr();
		switch(choice) {
			case 1 : if(isFull() == 1) {
					 puts("Stack Overflow !\n");
					 break;
				 }
				 printf("Enter data : ");
				 scanf("%d" , &data);
				 push(data);
				 puts("Data pushed !\n");
				 break;

			case 2 : if(top == NULL) {
					 puts("Stack Underflow !\n");
					 break;
				 }
				 pop();
				 puts("Data popped !\n");
				 break;

			case 3 : peek();
				 break;

			case 4 : puts("Exitting ... ");
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

void push(int data) {
	struct Node* new_node = create_node(data);
	new_node->next = top;
	top = new_node;
}

void pop() {
	struct Node* temp = top;
	top = top->next;
	free(temp);
}

void peek() {
	if(top == NULL) {
		puts("Stack Underflow !\n");
		return;
	}
	printf("Top Element = %d\n\n" , top->data);
}

int isFull() {
	struct Node* current = top;
	int count = 0;
	while(current != NULL) {
		current = current->next;
		count++;
	}
	if(count == CAPACITY) {
		return 1;
	}
	return 0;
}
