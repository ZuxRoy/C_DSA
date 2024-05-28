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
	struct Node* prev;
};

struct Node* create_node(int);
void insert_beginning(int);
void insert_end(int);
void insert_position(int , int);
void insert_after(int , int);
void delete_beginning();
void delete_end();
void delete_position(int);
void delete_value(int);
void search_node(int);
void update_node(int , int);
void count_node();
void display();
void reverse_list();
void palindrome_check();

struct Node* head = NULL;

int main() {
	int data , position;
	while(1) {
		printf("[1] Insert node in the beginning\n[2] Insert node at the end\n[3] Insert node at position\n[4] Insert node after position\n[5] Delete node in the beginning\n[6] Delete node at the end\n[7] Delete node at a position\n[8] Delete node by value\n[9] Search node by value\n[10] Update value of a node\n[11] Count number of nodes\n[12] Display list\n[13] Reverse list\n[14] Check is list is a plaindrome\n[15] Exit\nEnter choice : ");
		int choice;
		scanf("%d" , &choice);
		clrscr();
		switch(choice) {

			case 1 : printf("Enter data to insert : ");
				 scanf("%d" , &data);
				 insert_beginning(data);
				 break;

			case 2 : printf("Enter data to insert : ");
				 scanf("%d" , &data);
				 insert_end(data);
				 break;

			case 3 : printf("Enter data to insert : ");
				 scanf("%d" , &data);
				 if(head == NULL) {
					 puts("Linked List Empty .. inserting in the beginning !");
					 insert_beginning(data);
					 break;
				 }
				 printf("Enter position to insert at : ");
				 scanf("%d" , &position);
				 insert_position(data , position);
				 break;

			case 4 : printf("Enter data to insert : ");
				 scanf("%d" , &data);
				 if(head == NULL) {
					 puts("Linked List Empty .. inserting in the beginning !");
					 insert_beginning(data);
					 break;
				 }
				 printf("Enter position to insert after : ");
				 scanf("%d" , &position);
				 insert_after(data , position);
				 break;

			case 5 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 delete_beginning();
				 break;

			case 6 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 delete_end();
				 break;

			case 7 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 if(head->next == NULL) {
					 puts("Only one element in linked list ... deleting ");
					 delete_beginning();
					 break;
				 }
				 printf("Enter position to delete : ");
				 scanf("%d" , &position);
				 if(position == 1) {
					 delete_beginning();
					 break;
				 }
				 delete_position(position);
				 break;

			case 8 : if(head == NULL) {
					 puts("Linked List is Empty !\n");
					 break;
				 }
				 printf("Enter data to delete : ");
				 scanf("%d" , &data);
				 if(head->next == NULL) {
					 if(head->data != data) {
				  		puts("Data not found !\n");
						break;
					 }
				 }
				 if(head->data == data) {
					 delete_beginning();
					 break;
				 }
				 delete_value(data);
				 break;

			case 9 : if(head == NULL) {
                                         puts("Linked List is Empty !\n");
                                         break;
                                 }
                                 printf("Enter data to search : ");
                                 scanf("%d" , &data);
                                 if(head->next == NULL) {
                                         if(head->data == data) {                                                puts("Data found at index 1\n");
                                               break;
                                         }else{
                                                puts("Data not found !\n");
                                                break;
                                         }
                                 }
                                 search_node(data);
                                 break;

			case 10 : if(head == NULL) {
					  puts("Linked List is Empty !\n");
					  break;
				  }
				  printf("Enter node index : ");
				  scanf("%d" , &position);
				  if(head->next == NULL && position != 1) {
					  puts("Position not found !\n");
					  break;
				  }
				  printf("Enter new data : ");
				  scanf("%d" , &data);
				  update_node(data , position);
				  break;

			case 11 : if(head == NULL) {
					  puts("Linked List is Empty !\n");
					  break;
				  }
				  if(head->next == NULL) {
					  puts("1 node present in list\n");
					  break;
				  }
				  count_node();
				  break;

			case 12 : if(head == NULL) {
                                          puts("Linked List is Empty !\n");
                                          break;
                                  }
                                  display();
				  break;

			case 13 : if(head == NULL) {
					  puts("Linked List is Empty !\n");
					  break;
				  }
				  if(head->next == NULL) {
					  puts("List has been reversed !\n");
					  break;
				  }
				  reverse_list();
				  break;

			case 14 : if(head == NULL) {
					  puts("Linked List is Empty !\n");
					  break;
				  }
				  if(head->next == NULL) {
					  puts("List is Palindrome !\n");
					  break;
				  }
				  palindrome_check();
				  break;
				  
			case 15 : printf("Exitting...");
				  exit(0);

			default : printf("Wrong choice !");
		}
	}
}

struct Node* create_node(int data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = data;
	return new_node;
}

void insert_beginning(int data) {
	struct Node* new_node = create_node(data);
	if(head == NULL) {
		head = new_node;
		puts("Data inserted !\n");
		return;
	}
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
	puts("Data inserted !\n");
}

void insert_end(int data) {
	struct Node* new_node = create_node(data);
	if(head == NULL) {
		head = new_node;
		puts("Data inserted !\n");
		return;
	}
	struct Node* current = head;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = new_node;
	new_node->prev = current;
	puts("Data inserted !\n");
}

void insert_position(int data , int position) {
	struct Node* new_node = create_node(data);

	struct Node* current = head;
	struct Node* prev = NULL;

	for(int i=1; i != position && current != NULL; i++) {
		prev = current;
		current = current->next;
	}
	if(current == NULL) {
		puts("Position not found !\n");
		return;
	}
	prev->next = new_node;
	new_node->prev = prev;
	new_node->next = current;
	current->prev = new_node;
	puts("Data inserted !\n");
}

void insert_after(int data , int position) {
        struct Node* current = head;
        struct Node* prev = NULL;

        for(int i=0; i != position && current != NULL; i++) {
                prev = current;
                current = current->next;
		if(i==position-1 && current == NULL) {
			insert_end(data);
			return;
		}
        }
        if(current == NULL) {
                puts("Position not found !\n");
                return;
        }

	struct Node* new_node = create_node(data);

        prev->next = new_node;
        new_node->prev = prev;
        new_node->next = current;
        current->prev = new_node;
        puts("Data inserted !\n");
}

void delete_beginning() {
	if(head->next == NULL) {
		free(head);
		head = NULL;
		puts("Data Deleted !\n");
		return;
	}
	struct Node* temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
	puts("Data Deleted !\n");
}

void delete_end() {
	if(head->next == NULL) {
		delete_beginning();
		return;
	}
	struct Node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->prev->next = NULL;
	free(temp);
	puts("Data Deleted !\n");
}

void delete_position(int position) {
	struct Node* temp = head;
	for(int i=1 ; i != position && temp != NULL ; i++) {
		temp = temp->next;
	}
	if(temp == NULL) {
		puts("Position not found !\n");
		return;
	}
	if(temp->next == NULL) {
		temp->prev->next = NULL;
	}else{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	free(temp);
	puts("Data Deleted !\n");
}

void delete_value(int data) {
	struct Node* temp = head;
	int index = 0;
	while(temp != NULL) {
		index++;
		if(temp->data == data) {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			puts("Data Deleted !\n");
			return;
		}
		temp = temp->next;
	}
	if(temp == NULL) {
		puts("Data not found !\n");
	}
}

void search_node(int data) {
	struct Node* temp = head;
        int index = 0;
        while(temp != NULL) {
                index++;
                if(temp->data == data) {
                        printf("Data found at node %d\n\n" , index);
                        return;
                }
                temp = temp->next;
        }
        if(temp == NULL) {
                puts("Data not found !\n");
        }
}

void update_node(int data, int position) {
	struct Node* current = head;
	
	for(int i=1 ; i != position && current != NULL; i++) {
		current = current->next;
	}
	if(current == NULL) {
		puts("Position not found !\n");
		return;
	}
	current->data = data;
	puts("Data updated !\n");
}

void count_node() {
	struct Node* current = head;
	int index = 0;
	while(current != NULL) {
		current = current->next;
		index++;
	}
	printf("%d nodes present in list\n\n" , index);
}

void display() {
	struct Node* current = head;
	puts("Linked List : ");
	printf("Head->");
	while(current->next != NULL) {
		printf("%d->" , current->data);
		current = current->next;
	}
	printf("%d->NULL\n" , current->data);
	puts("\nReverse traversal :");
	printf("NULL->");
	while(current != NULL) {
		printf("%d->" , current->data);
		current = current->prev;
	}
	printf("HEAD\n\n");
}

void reverse_list() {
	struct Node* current = head;
	struct Node* prev = NULL;
	while(current != NULL) {
		prev = current;
		head = current;
		current = current->next;
		
		struct Node* temp = prev->prev;
		prev->prev = prev->next;
		prev->next = temp;
	}
	puts("List has been reversed !\n");
}

void palindrome_check() {
	struct Node* current = head;
        struct Node* reverse = head;
        while(reverse->next != NULL) {
                reverse = reverse->next;
        }
	while(current != NULL) {
		if(current->data != reverse->data) {
			puts("List is not Palindrome !\n");
			return;
		}
		current = current->next;
		reverse = reverse->prev;
	}
	puts("List is Palindrome !\n");
}

