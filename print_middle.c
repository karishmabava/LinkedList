/* 	Question: Print the middle element of the linked list */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void printMiddle(struct node *root){

	if(root == NULL){
		return;
	} else {
		struct node *temp=root;
		struct node *root1 = root;
		while(root1->next != NULL){
			  temp =  temp->next;
			  root1 = root1->next;
			  root1 = root1->next;
		}
	
		printf("%d\n", temp->data);
	}
}

int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    int i;
 
    for (i=5; i>0; i--)
    {
        push(&head, i);
        printList(head);
    }

	printMiddle(head); 
    return 0;
}
