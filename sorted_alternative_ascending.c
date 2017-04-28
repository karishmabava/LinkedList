#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// A utility function to create a new node
struct Node* newNode(int key)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	memset(temp, 0, sizeof(struct Node));

    temp->data = key;
    temp->next = NULL;
    return temp;
}

// A utility function to print a linked list
void printlist(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

	printf("\n");
}

void splitLinkedListOdd(struct Node *root, struct Node **Ahead, struct Node **Dhead){

	 *Ahead = newNode(0);
	 *Dhead = newNode(0);

	 struct Node *ascn=*Ahead, *dscn=*Dhead, *curr = root;
	 while(curr){
		   // Putting ascending order nodes
			ascn->next = curr;
			ascn = ascn->next;
			curr = curr->next;
				// Putting descending order nodes
			    if(curr){
				   dscn->next = curr;
				   dscn = dscn->next;
			       curr = curr->next;
			    }
	 }

	 ascn->next = NULL;
	 dscn->next = NULL;

     *Ahead = (*Ahead)->next;
	 *Dhead = (*Dhead)->next;
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

	    if(a->data < b->data){
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
    struct Node *head = newNode(10);
    head->next = newNode(40);
    head->next->next = newNode(53);
    head->next->next->next = newNode(30);
    head->next->next->next->next = newNode(67);
    head->next->next->next->next->next = newNode(12);
    head->next->next->next->next->next->next = newNode(89);
 
    printf("Given Linked List is ");
    printlist(head);
 	struct Node *even=NULL, *odd=NULL;
	splitLinkedListOdd(head, &odd, &even);	
	printf("Odd list\n");
	printlist(odd);
	printf("\n Even List \n");
	printlist(even);
	printf("\n");
	even = reverse(even);
	printf("After even reversed\n");
	printlist(even);
    /*sort(&head);*/
	head = SortedMerge(odd, even);
	printf("\n After Merge \n");
	printlist(head);  
	/*
    cout << "Sorted Linked List is " << endl;
    printlist(head);
 	*/
    return 0;
}

