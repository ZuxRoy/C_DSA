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
void input(struct Node** , int);
struct Node* merge(struct Node**  , struct Node**);
void check_intersection(struct Node** , struct Node**);
void display(struct Node**);

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
	
	check_intersection(&head1 , &head2);

	struct Node* head_merged = merge(&head1 , &head2);

	printf("\nMerged List : ");
	display(&head_merged);
}

struct Node* create_node(int data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->next = NULL;
	new_node->data = data;
	return new_node;
}

void input(struct Node** head , int size) {
	while(size--) {
		int data;
		printf("Add data : ");
		scanf("%d" , &data);
		struct Node* new_node = create_node(data);
		if(*head != NULL) {
			new_node->next = *head;
		}
		*head = new_node; 
	}
}

struct Node* merge(struct Node** head1 , struct Node** head2) {
	struct Node* current = *head1;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = *head2;
	return *head1;
}

void check_intersection(struct Node** head1 , struct Node** head2) {
	printf("\n");
	struct Node* current1 = *head1;
	int node1 = 0 , flag = 0;
	while(current1 != NULL) {
		node1++;
		struct Node* current2 = *head2;
		int node2 = 0;
		while(current2 != NULL) {
			node2++;
			if(current1->data == current2->data) {
				printf("Node %d of List1 and Node %d of List2 intersect\n" , node1 , node2);
				flag = 1;
			}
			current2 = current2->next;
		}	
		current1 = current1->next;
	}
	if(flag == 0) {
		puts("No intersecting nodes\n");
	}
}

void display(struct Node** head) {
	struct Node* current = *head;
	printf("HEAD->");
	while(current != NULL) {
		printf("%d->" , current->data);
		current = current->next;
	}
	printf("NULL\n");
}
