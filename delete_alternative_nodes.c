/* Delete the alternative node */
#include<stdio.h>
#include<stdlib.h>
 
/* A linked list node */
struct node
{
    int data;
    struct node *next;
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
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
void deleteAlt(struct node *root){

	 struct node *temp;

	  while(root->next != NULL){
			temp = root->next;
			root->next = temp->next;
			root = root->next;
	  }


}

/* Drier program to test above functions */
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    /* Using push() to construct below list
      1->2->3->4->5  */
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("\nList before calling deleteAlt() \n");
    printList(head);
 
    deleteAlt(head);
 
    printf("\nList after calling deleteAlt() \n");
    printList(head);
 
    return 0;
}
