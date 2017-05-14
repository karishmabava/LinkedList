/* Question: nth node from last
 * we will start two pointers: one from start and one(temp) from the nth distance from start
 * make the temp till end, start pointer pointing at the nth node from last
 */

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
 
void printNthFromLast(struct node *root, int n){
	
	 struct node *temp =root;

	 for(int i = 0; i<n; i++){
		 temp = temp->next;
	 }

	 while(temp != NULL){
		   temp = temp->next;
		   root =root->next;	
	}

	printf("Node is %d\n", root->data);
}

/* Drier program to test above function*/
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 35);
 
  printNthFromLast(head, 4);
}
