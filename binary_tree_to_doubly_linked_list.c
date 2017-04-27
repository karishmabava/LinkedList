/* Question: Convert a given Binary Tree to Doubly Linked List | Set 4
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

*/

// Complexity O(n)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
	memset(node, 0, sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void print_tree(struct Node *root){

	 if(root == NULL){
		return;
	 }

	print_tree(root->left);
	printf("%d ", root->data);
	print_tree(root->right);
}

// Constructing doubly linked list 
void BToDLL(struct Node *root, struct Node **head){

	 if(root == NULL){
		return;
	 }

	 BToDLL(root->right, head);
	 root->right = *head;
		if(*head != NULL){
		    (*head)->left = root;
	    } 

	 *head = root;
	 BToDLL(root->left, head);
}

// Utility function for printing double linked list.
void printList(struct Node* head)
{
    printf("Extracted Double Linked list is:\n");
    while (head)
    {
        printf("%d ", head->data);
        head = head->right;
    }
}

int main()
{
    /* Constructing below tree
               5
             /   \
            3     6
           / \     \
          1   4     8
         / \       / \
        0   2     7   9  */
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->right = newNode(8);
    root->left->left->left = newNode(0);
    root->left->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(9);
 	print_tree(root);
	
    struct Node* head = NULL;
    BToDLL(root, &head);
 
    printList(head);
 
    return 0;
} 
