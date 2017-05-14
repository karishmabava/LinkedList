/*Question: Swap kth node from start and end */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// A Linked List node
struct node
{
    int data;
    struct node *next;
};
 
/* Utility function to insert a node at the beginning */
void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
/* Utility function for displaying linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct node * find_kth_node_from_start(struct node *root, int k, int n){

	 struct node *temp=NULL;

	  if(k==0){
		 return root;
	  } else if (k==1){
		 return root->next;
	  } else {
		 for(int i=0; i<n; i++){
			 if(i==k-1){
				temp = root;
				return temp;
			 }
			 root = root->next;
		 }
	  }
	 return NULL;
}

struct node * find_kth_node_from_end(struct node *root, int k, struct node *startKthNode){
	
	   struct node *temp=NULL;

	   while(startKthNode != NULL){
			 root= root->next;
			 startKthNode = startKthNode->next;
		}

		return root;
}

void swap(struct node *a, struct node *b){
		
     int temp;
	 temp = b->data;
	 b->data = a->data;
	 a->data = temp;
}

void swapKth(struct node **head, int k){

	 struct node *root = *head;
	 struct node *curr = *head;
	 struct node *startKthNode=NULL;
	 struct node *endKthNode=NULL;
	 int counter =0;
 
	 // Finding the length of the linked list
	 while(curr != NULL){
		   counter++;
		   curr = curr->next;
	 }

	 startKthNode = find_kth_node_from_start(root, k, counter);
	 endKthNode = find_kth_node_from_end(root, k, startKthNode);
	 printf("Start kth node is %d\n", startKthNode->data);
	 printf("Last kth node is %d\n", endKthNode->data);
	 swap(startKthNode, endKthNode);
}

// Driver program to test above functions
int main()
{
    // Let us create the following linked list for testing
    // 1->2->3->4->5->6->7->8
    struct node *head = NULL;
    for (int i = 8; i >= 1; i--)
       push(&head, i);
 
    printf("Original Linked List: ");
    printList(head);
 
	swapKth(&head, 3);

   for (int k = 1; k < 9; k++)
    {
        swapKth(&head, k);
        printf("\nModified List for k:%d is ", k);
        printList(head);
    } 
 	
	printf("\n");
    return 0;
} 
