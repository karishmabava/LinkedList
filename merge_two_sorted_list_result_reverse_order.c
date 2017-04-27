/* Question: Merge two sorted linked lists such that merged list is in reverse order
Given two linked lists sorted in increasing order. Merge them such a way that the result list is in decreasing order (reverse order).

Examples:

Input:  a: 5->10->15->40
        b: 2->3->20 
Output: res: 40->20->15->10->5->3->2

Input:  a: NULL
        b: 2->3->20 
Output: res: 20->3->2 */

/* Solution: 
1) Initialize result list as empty: res = NULL.
2) Let 'a' and 'b' be heads first and second lists respectively.
3) While (a != NULL and b != NULL)
    a) Find the smaller of two (Current 'a' and 'b')
    b) Insert the smaller value node at the front of result.
    c) Move ahead in the list of smaller node. 
4) If 'b' becomes NULL before 'a', insert all nodes of 'a' 
   into result list at the beginning.
5) If 'a' becomes NULL before 'b', insert all nodes of 'a' 
   into result list at the beginning. 
*/

// Complexity O(n)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/* Link list Node */
struct Node
{
    int key;
    struct Node* next;
};

/* Function to print Nodes in a given linked list */
void printList(struct Node *Node)
{
    while (Node!=NULL)
    {
        printf("%d ", Node->key);
        Node = Node->next;
    }
}
 
/* Utility function to create a new node with
   given key */
struct Node *newNode(int key)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	memset(temp, 0, sizeof(struct Node));

    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
struct Node * SortedMerge(struct Node *a, struct Node *b){

	struct Node *res=NULL;

	if(a == NULL && b == NULL){
	   return NULL;	
	} 

	if(a == NULL){
	   return b;
	}

	if(b == NULL){
	   return a;
	}
	
	while(a != NULL && b != NULL){

	    if(a->key < b->key){
		   struct Node *temp = a->next;
		   a->next = res;
		   res = a;
		   a = temp;
		} else {
			struct Node *temp = b->next;
			b->next = res;
			res = b;
			b = temp;
		}

	}

	// If 'a' hasnt finished and 'b' has finished then add all a into the
	// Front of the res
	while(a != NULL){
		  struct Node *a_temp = a->next;
		  a->next = res;
		  res = a;
		  a = a_temp;
	}

	// If 'b' hasnt finished and 'a' has finished then add all b into the front 
	// of a
	while(b != NULL){
		  struct Node *b_temp = b->next;
	      b->next = res;
		  res = b;
	      b = b_temp;
	}

	return res;
}

int main()
{
    /* Start with the empty list */
    struct Node* res = NULL;
 
    /* Let us create two sorted linked lists to test
       the above functions. Created lists shall be
         a: 5->10->15
         b: 2->3->20  */
    struct Node *a = newNode(5);
    a->next = newNode(10);
    a->next->next = newNode(15);
 
    struct Node *b = newNode(2);
    b->next = newNode(3);
    b->next->next = newNode(20);
 
    printf("List A before merge: \n");
    printList(a);
 
    printf("\nList B before merge: \n");
    printList(b);
 
    /* merge 2 increasing order LLs in descresing order */
    res = SortedMerge(a, b);
 
    printf("\nMerged Linked List is: \n");
    printList(res);
 
    return 0;
}
