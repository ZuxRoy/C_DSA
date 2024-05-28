#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = NULL;

struct Node* create_node(int);
void insert_beginning(int);
void insert_end(int);
void insert_position(int , int);
void delete_beginning();
void delete_end();
void delete_position(int);
void search_node(int);
void display();
void count_node();
void reverse_list();
void circular_traversal();
int main() {
	int data , position;
	while(1) {
		int choice;
		printf("\n[1] Insert at the beginning\n[2] Insert at the end\n[3] Insert at a position\n[4] Delete from the beginning\n[5] Delete from the end\n[6] Delete from a position\n[7] Search a value\n[8] Display list\n[9] Count number of nodes\n[10] Reverse list\n[11] Circular List Trasversal\n[12] Exit\nEnter choice : ");
		scanf("%d" , &choice);	
		clrscr();
		switch(choice) {
			case 1 : printf("Enter data : ");
				 scanf("%d" , &data);
				 insert_beginning(data);
				 break;

			case 2 : printf("Enter data : ");
				 scanf("%d" , &data);
				 if(head == NULL) {
					 insert_beginning(data);
					 break;
				 }
				 insert_end(data);
				 break;

			case 3 : printf("Enter data : ");
				 scanf("%d" , &data);
				 if(head == NULL) {
					 puts("Linked List is Empty ... Data will be inserted in the beginning !");
					 insert_beginning(data);
					 break;
				 }
				 printf("Enter position : ");
				 scanf("%d" , &position);
				 if(position == 1) {
					 insert_beginning(data);
					 break;
				 }
				 insert_position(data , position);
				 break;

			case 4 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 delete_beginning();
				 break;

			case 5 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 delete_end();
				 break;

			case 6 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 printf("Enter position : ");
				 scanf("%d" , &position);
				 delete_position(position);
				 break;

			case 7 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 printf("Enter data : ");
				 scanf("%d" , &data);
				 if(head->next->data == data) {
					 puts("Element found at node 1\n");
					 break;
				 }
				 search_node(data);
				 break;

			case 8 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 display();
				 break;

			case 9 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 count_node();
				 break;

			case 10 : if(head == NULL) {
					  puts("Linked List is Empty !\n");
					  break;
				  }
				  if(head->next == NULL) {
					  puts("List has been reversed !\n");
					  break;
				  }
				  reverse_list();
				  break;

			case 11 : if(head == NULL) {
					  puts("Linked List is Empty !\n");
					  break;
				  }
				  circular_traversal();
				  break;

			case 12 : puts("Exitting ...");
				  exit(0);
				  break;
				
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

void insert_beginning(int data) {
	struct Node* new_node = create_node(data);
	struct Node* temp = head;
	new_node->next = head;
	head = new_node;
	if(new_node->next == NULL) {
		new_node->next = head;
	}else{
		struct Node* current = temp;
		while(current->next != temp) {
	       		current = current->next;
		}
		current->next = head;	
	}
	puts("Data inserted !\n");
}

void insert_end(int data) {
	struct Node* new_node = create_node(data);
	struct Node* current = head;
	while(current->next != head) {
		current = current->next;
	}
	current->next = new_node;
	new_node->next = head;
	puts("Data inserted !\n");
}

void insert_position(int data , int position) {
	struct Node* current = head;
	struct Node* prev = head;
	for(int i = 1; i != position; i++) {
		prev = current;
		current = current->next;
		
		if(current == head) {
			puts("Position not found !\n");
			return;
		}
	}
	struct Node* new_node = create_node(data);
	new_node->next = current;
	prev->next = new_node;
	puts("Data inserted !\n");
}

void delete_beginning() {
	struct Node* temp = head;
	if(head->next == head) {
		head = NULL;
		free(temp);
		puts("Data deleted !\n");
		return;
	}
	head = head->next;
	struct Node* current = head;
	while(current->next != temp) {
		current = current->next;
	}
	current->next = head;
	free(temp);
	puts("Data deleted !\n");
}

void delete_end() {
	if(head->next == head) {
		delete_beginning();
		return;
	}
	struct Node* temp = head;
	struct Node* prev = NULL;
	while(temp->next != head) {
		prev = temp;
		temp = temp->next;
	}
	prev->next = head;
	free(temp);
	puts("Data deleted !\n");

}

void delete_position(int position) {
	if(position == 1) {
		delete_beginning();
		return;
	}
	struct Node* temp = head;
	struct Node* prev = NULL;
	for(int i = 1; i != position; i++) {
		prev = temp;
		temp = temp->next;
		if(temp == head) {
			puts("Position not found !\n");
			return;
		}
	}	
	
	prev->next = temp->next;
	free(temp);
	puts("Data deleted !\n");
}

void search_node(int data) {
	if(head->data == data) {
		puts("Data found at node 1\n");
		return;
	}
	struct Node* current = head->next;
	int index = 1;
	while(current != head) {
		index ++;
		if(current->data == data) {
			printf("Data found at node %d\n\n" , index);
			return;
		}
		current = current->next;
	}
	puts("Data not found !\n");
}

void display() {
	struct Node* current = head->next;
	puts("Circular Linked List : \n");
	printf("HEAD->%d->" , head->data);
	while(current != head) {
		printf("%d->" , current->data);
		current = current->next;
	}
	printf("HEAD\n\n");
}

void count_node() {
	struct Node* current = head->next;
	int count = 1;
	while(current != head) {
		count++;
		current = current->next;
	}
	printf("%d nodes present in list !\n\n" , count);
}

void reverse_list() {
	struct Node* current = head->next;
	struct Node* prev = head;
	struct Node* next = NULL;
	while(current != head) {
		next = current->next;
		current->next = prev;		

		prev = current;
		current = next;
	}
	head->next = prev;
	head = prev;
	puts("List has been reversed !\n");
}

void circular_traversal() {
	struct Node* current = head;
	while(1) {
		clrscr();
		printf("Current node : %d\n\n" , current->data);
		printf("Press [N] to move to next node\nPress [E] to exit\nEnter : ");
		char ch = getchar();
		if(ch == 'n' || ch == 'N') {
			current = current->next;
		}else if(ch == 'e' || ch == 'E') {
			puts("Traversal Terminated !\n");
			return;
		}else{
			puts("Wrong choice !\n");
		}
	}
}
