/*Question: Sort linked list which is already sorted on absolute values
Given a linked list which is sorted based on absolute values. Sort the list based on actual values.

Examples:

Input :  1 -> -10 
output: -10 -> 1

Input : 1 -> -2 -> -3 -> 4 -> -5 
output: -5 -> -3 -> -2 -> 1 -> 4 

Input : -5 -> -10 
Output: -10 -> -5

Input : 5 -> 10 
output: 5 -> 10

Solution: An important observation is, all negative elements are present in reverse order. So we traverse the list, whenever we find an element that is out of order, we move it to the front of linked list. */

// Complexity O(n)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Linked List Node
struct Node
{
    struct Node* next;
    int data;
};
 
// Utility function to insert a node at the
// beginning
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
	memset(newNode, 0, sizeof(struct Node));
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}

// Utility function to print a linked list
void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
}

void sortList(struct Node **head){
	
	struct Node *curr = (*head)->next;
	struct Node *prev = *head;
	struct Node *temp= NULL;
	 while(curr != NULL){
		   
	 	   if(curr->data < prev->data){
			  prev->next = curr->next;
			  curr->next = *head;
			  *head = curr;
			  curr = prev;
		   } else {	
		      prev = curr;
		   }
		 
	       curr = curr->next;
	 }

}

int main()
{
    struct Node* head = NULL;
    push(&head, -5);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, -2);
    push(&head, 1);
    push(&head, 0);
 
    printf("Original list :\n");
    printList(head);
 
	sortList(&head);
 
    printf("\nSorted list :\n");
    printList(head);
 
    return 0;
}
