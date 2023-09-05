#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* createNode(int data){
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insertBeginning(struct Node** head , int data){
  struct Node* new_node = createNode(data);
  new_node->next = *head;
  *head = new_node;
}

void insertEnd(struct Node** head , int data){
  struct Node* new_node = createNode(data);
  if(*head == NULL){
    *head = new_node;
    return;
  }

  struct Node* current = *head;
  
  while(current->next != NULL){
    current = current->next;
  }
  current->next = new_node;
}

void insertAtPosition(struct Node** head , int position , int data){
  if(position == 0){
    insertBeginning(head , data);
    return;
  }

  struct Node* new_node = createNode(data);
  struct Node* current = *head;
  
  for(int i=1;i<position && current != NULL; i++){
    current = current->next;
  }
  if(current == NULL){
    insertEnd(head , data);
  }else{
    new_node->next = current->next;
    current->next = new_node;
  }
}

void deleteNodeBeginning(struct Node** head){
  if(*head == NULL){
    printf("Linked List Empty !\n");
    return;
  }
  struct Node* temp = *head;
  *head = (*head)->next;
  free(temp);
  printf("Data Deleted !\n");
}

void deleteNodeEnd(struct Node** head){
  if(*head == NULL){
    printf("Linkned List Empty !\n");
    return;
  }

  while((*head)->next == NULL){
    free(*head);
    *head = NULL;
    printf("Data Deleted !\n");
    return;
  }

  struct Node* current = *head;
  while(current->next->next != NULL){
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
  printf("Data Deleted !\n");
}

void deleteNodePosition(struct Node** head , int position){
  if(*head == NULL){
    printf("Linked List Empty !\n");
    return;
  }

  if(position == 0){
    deleteNodeBeginning(head);
    return;
  }

  struct Node* current = *head;
  struct Node* previous = NULL;
  for(int i=0;i < position && current != NULL;i++){
    previous = current;
    current = current->next;
  }

  if(current == NULL){
    printf("Position not present in Linked List !\n");
    return;
  }

  previous->next = current->next;
  free(current);
  printf("Element Deleted !\n");
}

void printList(struct Node* head){
  struct Node* current = head;
  while(current != NULL){
    printf("%d -> " , current->data);
    current = current->next; 
  }
  printf("NULL\n");
}

int main(){

  struct Node* head = NULL;

  int choice,position,data;
  do{
    printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert At Position\n4. Delete Node from Beginning\n5. Delete Node from End\n6. Delete Node from Position\n7. Print List\n8. Exit\nEnter choice : ");
    scanf("%d" , &choice);
    switch(choice){

      case 1:
        printf("Enter data to insert : ");
        scanf("%d" , &data);
        insertBeginning(&head , data);
        printf("Data Inserted !\n");
        break;
        
      case 2:
        printf("Enter data to insert : ");
        scanf("%d" , &data);
        insertEnd(&head , data);
        printf("Data Inserted !\n");
        break;

      case 3:
        printf("Enter data to insert : ");
        scanf("%d" , &data);
        printf("Enter position to insert at : ");
        scanf("%d" , &position);
        insertAtPosition(&head , position , data);
        printf("Data Inserted !\n");
        break;

      case 4:
        deleteNodeBeginning(&head);
        break;

      case 5:
        deleteNodeEnd(&head);
        break;

      case 6:
        printf("Enter position to delete from : ");
        scanf("%d" , &position);
        deleteNodePosition(&head , position);
        break;

      case 7:
        printList(head);
        break;

      case 8: 
        printf("\nExiting ... ");
        break;

      default: printf("\nWrong choice !\n");
    }
  }while(choice != 8); 
}