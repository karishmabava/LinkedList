// C program for merge sort on doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
};
 
struct node *split(struct node *head);

void insert(struct node **head, int data)
{
    struct node *temp =
        (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct node *head)
{
    struct node *temp = head;
    printf("Forward Traversal using next poitner\n");
    while (head)
    {
        printf("%d ",head->data);
        temp = head;
        head = head->next;
    }
    printf("\nBackward Traversal using prev pointer\n");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

struct node * merge(struct node *first, struct node *second){

	 if(first == NULL){
		return second;
	 }
	 
	 if(second == NULL){
		return first;
	 }

	 if(first->data < second->data){
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	 } else {
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	 }
}


struct node * split(struct node *root){
	
	   struct node *fast=root;
	   struct node *slow=root;


	   while(fast->next && fast->next->next){
			 fast = fast->next->next;
			 slow = slow->next;
	   }
	  struct node *temp = slow->next;
	  slow->next = NULL;
	  return temp;
}

struct node * mergeSort(struct node *root){

	if(root == NULL || root->next == NULL){
		return root;
	}

	struct node *second = split(root);
	root = mergeSort(root);
	second = mergeSort(second);

	return merge(root, second);
}

int main(void)
{
    struct node *head = NULL;
    insert(&head,5);
    insert(&head,20);
    insert(&head,4);
    insert(&head,3);
    insert(&head,30);
    insert(&head,10);
    head = mergeSort(head);
    printf("\n\nLinked List after sorting\n");
    print(head);
	printf("\n");
    return 0;
}
