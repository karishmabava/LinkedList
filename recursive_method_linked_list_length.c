/* Find the length of the linked list in recursive method */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* Given a reference (pointer to pointer) to the head
  of a list and an int, push a new node on the front
  of the list. */
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

int getCount(struct node * head){

	if(head == NULL){
		return 0;
	}

	return 1 + getCount(head->next);
}

/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    /* Use push() to construct below list
     1->2->1->3->1  */
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
 
    /* Check the count function */
    printf("count of nodes is %d\n", getCount(head));
    return 0;
}
