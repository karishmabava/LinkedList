/* Removing duplicates from linked list */
#include<stdio.h>
#include<stdlib.h>
 
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
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node!=NULL)
    {
       printf("%d ", node->data);
       node = node->next;
    }

	printf("\n");
} 
 
void removeDuplicates(struct node *root){

	 int hash[1000] = {0};
	 struct node *prev;

	 while(root != NULL){
	
		   if(hash[root->data] == 1){
			  prev->next = root->next;
			  free(root);
			  root = prev;
		   } else {
			  hash[root->data] = 1;
		   } 
			prev = root;
			root = root->next;
	 }
	 
}

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 11->11->11->13->13->20 */
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);  
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);                                    
 
    printf("\n Linked list before duplicate removal  ");
    printList(head); 
 
    /* Remove duplicates from linked list */
    removeDuplicates(head); 
 
    printf("\n Linked list after duplicate removal \n"); 
    printList(head);            
   
    return 0;
}
