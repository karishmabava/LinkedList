/* Reverse a linked list */

#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* Function to push a node */
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
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}    
 
void reverse(struct node **root){

	struct node *curr=*root;
	struct node *prev = NULL;
	struct node *next;

	while(curr != NULL){
		  next = curr->next;
		  curr->next = prev;	
		  prev = curr;
		  curr = next;
	}

	*root = prev;
}

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     printf("Given linked list\n");
     printList(head);    
     reverse(&head);                      
     printf("\nReversed Linked list \n");
     printList(head);    
	 printf("\n");
	 return 1;
}
