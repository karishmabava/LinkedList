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

bool find_element(struct node *head, int val){
	
	 if(head == NULL){
		return false;
	 }

	 if(head->data == val){
		return true;
	 }

	 return find_element(head->next, val);

}
/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
	int element;	

	printf("Enter the element \n");
	scanf("%d", &element);

    /* Use push() to construct below list
     1->2->1->3->1  */
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    /* Check the count function */
    bool val = false;
	val = find_element(head, element);
		if(val == true){
			printf("Element found\n");
		} else {
			printf("Element did not found\n");
		}		

	return 0;
}

