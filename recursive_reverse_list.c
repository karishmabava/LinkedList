/*Question: Reverse a linked list recursively */
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

void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
  
    /* put in the data  */
    new_node->data  = new_data;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);   
  
    /* move the head to pochar to the new node */
    (*head_ref)    = new_node;
} 
 
void reverse(struct node *root){
	 if(root == NULL){
		return;
	 }

	 reverse(root->next);
	 printf("%d ", root->data);

}
 
/* Drier program to test above function*/
int main()
{
    // Let us create linked list 1->2->3->4
    struct node* head = NULL;    
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
   
    reverse(head);
    return 0;
}
