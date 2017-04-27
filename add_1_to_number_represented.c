/* Question: Add 1 to a number represented as linked list
Number is represented in linked list such that each digit corresponds to a node in linked list. Add 1 to it. For example 1999 is represented as (1-> 9-> 9 -> 9) and adding 1 to it should change it to (2->0->0->0) */

// Solution: Reverse the list, add one in it and then reverse it again.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};
 
/* Function to create a new node with given data */
struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	memset(new_node, 0, sizeof(struct Node));

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// A utility function to print a linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node * reverse(struct Node *root){

	 struct Node *curr = root;
	 struct Node *temp= NULL, *prev = NULL;
	 while(curr != NULL){
		   temp = curr->next;
		   curr->next = prev;
		   prev = curr;
		   curr = temp;			
	 }

	return prev;
}

struct Node * add_one(struct Node *root){

	int carry = 0;
	struct Node *curr = root;
	  curr->data = root->data+1;
	  if(curr->data >= 10){
		 carry = 1;
		 curr->data = (curr->data)%10;
	  }
	curr = curr->next;
	while(curr != NULL){
	    if((curr->data + carry) >= 10){
		    carry = (curr->data + carry)/10;
		    curr->data = (curr->data + 1)%10;  
		}else {
		    curr->data = curr->data + carry;
		}
		curr = curr->next;
	} 

     return root;
}
 
/* Driver program to test above function */
int main(void)
{
    struct Node *head = newNode(1);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);
 
    printf("List is ");
    printList(head);
 
	head = reverse(head);
	head = add_one(head); 
    printf("\nResultant list is ");
	head = reverse(head);
    printList(head);
 
    return 0;
}
