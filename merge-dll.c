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
	struct Node* prev;
};

struct Node* create_node(int);
void input(struct Node** , int);
struct Node* merge(struct Node**  , struct Node**);
void check_intersection(struct Node** , struct Node**);
void display(struct Node**);
void traverse(struct Node**);

int main() {

        struct Node* head1 = NULL;
        struct Node* head2 = NULL;

        int size1 = 0 , size2 = 0;

        puts("Input of Singly Linked List 1 :");
        printf("Size : ");
        scanf("%d" , &size1);
        input(&head1 , size1);

        puts("\nInput of Singly Linked List 2 :");
        printf("Size : ");
        scanf("%d" , &size2);
        input(&head2 , size2);

        clrscr();

        printf("List 1 : ");
        display(&head1);
        printf("List 2 : ");
        display(&head2);

	puts("");
        check_intersection(&head1 , &head2);

        struct Node* head_merged = merge(&head1 , &head2);

        printf("\nMerged List : ");
        display(&head_merged);

	printf("\nPress a key to move on to traversal\n");
	getchar();
	if(getchar()) {
		traverse(&head_merged);
	}
}

struct Node* create_node(int data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = data;
	return new_node;
}

void input(struct Node** head , int size) {
	while(size--) {
		printf("Add data : ");
		int data;
		scanf("%d" , &data);
		struct Node* new_node = create_node(data);
		if(*head == NULL) {
			*head = new_node;
		}else{
			struct Node* current = *head;
			while(current->next != NULL) {
				current = current->next;
			}
			current->next = new_node;
			new_node->prev = current;
		}
		
	}
}

struct Node* merge(struct Node** head1 , struct Node** head2) {
	struct Node* current = *head1;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = *head2;
	(*head2)->prev = current;
	return *head1;
}

void check_intersection(struct Node** head1 , struct Node** head2) {
	struct Node* current1 = *head1;
	int index1 = 0 , flag = 0;
	while(current1 != NULL) {
		index1++;
		struct Node* current2 = *head2;
		int index2 = 0;
		while(current2 != NULL) {
			index2++;
			if(current1->data == current2->data) {
				flag = 1;
				printf("Node %d of list1 intersects with Node %d of list2\n" , index1 , index2);
			}
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	if(flag == 0) {
		printf("No intersections found\n");
	}
}

void display(struct Node** head) {
	struct Node* current = *head;
	printf("HEAD<->");
	while(current != NULL) {
		printf("%d<->" , current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void traverse(struct Node** head) {
	struct Node* current = *head;
	struct Node* null_prev = NULL;
	while(1) {
		clrscr();
		puts("Traverse List :\n");
		printf("Current Element : ");
		if(current != NULL) {
			printf("%d" , current->data);
		}else{
			printf("NULL");
		}
		puts("\nPress [n] to move to next node\nPress [p] to move to previous node\nPress [e] to exit");
		char ch = getchar();
		if(current == NULL) {
			if(null_prev == *head) {
			       if(ch == 'n' || ch == 'N') {
				       current = null_prev;
			       }
			}else{
				if(ch == 'p' || ch == 'P') {
					current = null_prev;
				}
			}
			if(ch == 'e' || ch == 'E') {
				clrscr();
                                puts("Traversal Terminated ...");
                                return;
			}	
		}else{
			if(ch == 'n' || ch == 'N') {
				null_prev = current;
				current = current->next;
			}else if(ch == 'p' || ch == 'P') {
				null_prev = current;
				current = current->prev;	
			}else if(ch == 'e' || ch == 'E') {
				clrscr();
				puts("Traversal Terminated ...");
				return;
			}
		}
	}
}

