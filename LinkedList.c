#include <stdio.h>
#include<stdlib.h>
#ifdef _WIN32
#include<conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

struct Node{
	int data;
	struct Node* next;
};

struct Node* create_node(int);
void insert_beginning(int);
void insert_end(int);
void insert_position(int , int);
void delete_beginning();
void delete_end();
void delete_position(int);
void display();

struct Node* head = NULL;

int main() {
	while(1) {
		printf("\n[1] Insert data in the beginning\n[2] Insert data at the end\n[3] Insert data at position\n[4] Delete data from beginning\n[5] Delete data from end\n[6] Delete data from position\n[7] Print List\n[8] Exit\nEnter choice :  ");
		int choice;
		scanf("%d" , &choice);
		clrscr();
		int data,position;

		switch(choice) {
			
			case 1 : 
				 printf("Enter data : ");
				 scanf("%d" , &data);
				 insert_beginning(data);
				 break;

			case 2 : 
				 printf("Enter data : ");
				 scanf("%d" , &data);
				 insert_end(data);
				 break;

			case 3 : 
				 if(head == NULL) {
					 printf("Linked List empty ... inserting in the beginning\nEnter data : ");
					 scanf("%d" , &data);
					 insert_beginning(data);
					 break;
				 }
				 printf("Enter position : ");
				 scanf("%d" , &position);
				 printf("Enter data : ");
				 scanf("%d" , &data);
				 insert_position(data , position);
				 break;

			case 4 : 
				 delete_beginning();
				 break;

			case 5 : 
				 delete_end();
				 break;

			case 6 : 
				 if(head == NULL){
					 printf("Linked List is empty !\n");
				 }else{
					 printf("Enter position : ");
					 scanf("%d" , &position);
					 delete_position(position);
				 }
				 break;

			case 7 : 
				 display();
				 break;

			case 8 : 
				 printf("Exitting ...");
				 exit(0);

			default : printf("Wrong choice !");
		}
	}
}

struct Node* create_node(int data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

void insert_beginning(int data) {
	struct Node* new_node = create_node(data);
	if(head == NULL) {
		head = new_node;
	}else{
		new_node->next = head;
		head = new_node;
	}
	printf("Data inserted !\n");
}

void insert_end(int data) {
	struct Node* current = head;
	
	if(current == NULL) {
		insert_beginning(data);
		return;
	}
	struct Node* new_node = create_node(data);
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = new_node;
	printf("Data inserted !\n");
}

void insert_position(int data , int position) {
	int flag = 0;
	struct Node* current = head;
	if(current == NULL || position == 1) {
		insert_beginning(data);
		return;
	}
	
	struct Node* new_node = create_node(data);
	for(int i=1; i < position && current->next != NULL; i++) {
		if(i == 1) {
			current = head;
		}else{
			current = current->next;
		}
		if(i == position-1) {
			flag = 1;
		}
	}
	if(flag == 0) {
		printf("Position doesn't exit !\n");
	}else{
		new_node->next = current->next;
		current->next = new_node;
		printf("Data inserted !\n");
	}
}

void delete_beginning(){
	if(head == NULL) {
		printf("Linked List is empty !\n");
		return;
	}
	struct Node* temp = head;
	head = head->next;
	free(temp);
	printf("Data deleted !\n");
}

void delete_end(){
	if(head == NULL) {
		printf("Linked List is empty !\n");
		return;
	}
	if(head->next == NULL) {
		free(head);
		head = NULL;
		printf("Data deleted !\n");
		return;
	}
	struct Node* temp = head;
	struct Node* prev = head;
	while(temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	free(temp);
	printf("Data deleted !\n");

}

void delete_position(int position){
	if(head == NULL) {
		printf("Linked List is empty !\n");
	}else{
		if(position == 1) {
			delete_beginning();
			return;
		}
		int flag = 0;
		struct Node* temp = head;
		struct Node* prev = head;
		for(int i=1; i < position && temp->next != NULL; i++) {
			prev = temp;
			temp = temp->next;
			if(i == position-1) {
				flag =1;
			}
		}
		if(flag ==0) {
			printf("Position not present !\n");
		}else{
			prev->next = temp->next;
			free(temp);
			printf("Data deleted !\n");
		}
	}
}

void display() {
	struct Node* current = head;

	if(head == NULL){
		printf("Linked List is empty !\n");
	}else{
		printf("Linked List currently :\n");
		printf("Head -> ");
		while(current != NULL){
			printf("%d -> " , current->data);
			current = current->next;
		}
		printf("NULL\n");
	}
}

