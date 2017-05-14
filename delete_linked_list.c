/* Question: Delete a linked list */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 
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

void deleteList(struct node **root){
	
	struct node *temp=NULL;
	
	 if(root == NULL){
		return;
	 }

	 while(*root != NULL){
		   temp = (*root)->next;
		   free(*root);
		   *root = temp;
	 }
} 

/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    
    /* Use push() to construct below list
     1->12->1->4->1  */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1); 
    push(&head, 12);
    push(&head, 1);   
    
    printf("\n Deleting linked list");
    deleteList(&head);  
    
    printf("\n Linked list deleted");
}
