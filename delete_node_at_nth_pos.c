/* Delete a Linked List node at a given position
Given a singly linked list and a position, delete a linked list node at the given position.
Example:
Input: position = 1, Linked List = 8->2->3->1->7
Output: Linked List =  8->3->1->7

Input: position = 0, Linked List = 8->2->3->1->7
Output: Linked List = 2->3->1->7 */

/* Solution: Iterate throught he list till you hit the nth node, remove it,
 plumb previous node to next*/

// Worst case complexity: O(n)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct node
{
    int data;
    struct node *next;
};


/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(struct node **head, int data){

	struct node *temp = *head;

	struct node *root = (struct node *)malloc(sizeof(struct node));
	memset(root, 0, sizeof(struct node));

	root->data = data;
	root->next = NULL;

	if(*head == NULL){
		*head = root;
		return;
	}  else {

		while(temp != NULL){	
			  if(temp->next == NULL){
				 temp->next = root;
				 return;
			  } 
			  temp = temp->next;
		}
	}
}

void deleteNode(struct node **head, int node_num){

	struct node *temp= *head;
	struct node *prev = *head;

	if(*head == NULL){	
		return;
	}

	int count=0;
	while(temp != NULL){
		  if(count == node_num-1){
			 prev->next = temp->next;	
			 free(temp);
			 return;		 
		  }
		  count++;
		  prev = temp;
		  temp = temp->next;
	}

}
 
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
	printf("\n");
}
 
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8); 
 
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 4);
    puts("\nLinked List after Deletion at position 4: ");
    printList(head);
    return 0;
}
