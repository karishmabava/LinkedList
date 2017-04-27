#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **head, int data){

	struct node *temp=*head;
	
	if(*head == NULL){
	   *head = (struct node *)malloc(sizeof(struct node));
	   memset(*head, 0, sizeof(struct node));
	   (*head)->data = data;
	   (*head)->next = NULL;
	   return;	
	} else {
	   struct node *root = (struct node *)malloc(sizeof(struct node));
	   memset(root, 0, sizeof(struct node));
	   root->data = data;
	   root->next = NULL;	
	   	 while(temp != NULL){
			   if(temp->next == NULL){
				  temp->next = root;
				  return;
				}
				temp = temp->next;
		 }
	}
	return;
}

void printList(struct node *root)
{
    while (root != NULL)
    {
        printf(" %d ", root->data);
        root = root->next;
    }
}


int main(){

	struct node *head = NULL;
	push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	printf("\n");
    puts("Created Linked List: ");
    printList(head);
	printf("\n");

	int key = 2; // You can make it taken this value by user, for simplicity I just
				 // made it simple

	int count = 0;
	struct node *root = head, *prev = NULL, *node_delete = NULL, *node_delete_prev = NULL;
	while(root != NULL){
		  if(root->data == key){
			 node_delete = root;
			 node_delete_prev = prev;
		  }

		  prev = root;
		  root = root->next;
	}

	if(node_delete != NULL){
		node_delete_prev->next = node_delete->next;
		free(node_delete);
	}
	printf("After deletion\n");
	printList(head);
	return 1;
}
