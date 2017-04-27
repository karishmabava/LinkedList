/* Question: Check if a linked list of strings forms a palindrome
Given a linked list handling string data, check to see whether data is palindrome or not?
For example,

Input  : a -> bc -> d -> dcb -> a -> NULL
Output : True
String "abcddcba" is palindrome.

Output : a -> bc -> d -> ba -> NULL
Output : False
String "abcdba" is not palindrome. */

/* Solution: We would store the characters into a string and then check if the string is a palindrome or not. */

// Complexity O(n), It required extra space of string to hold characters
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/* Link list node */
struct Node
{
    char  *data;
    struct Node* next;
};

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%s",node->data); 
		printf(" -> ");
        node = node->next;
    }
    printf("NULL\n");
}
 
struct Node *newNode(const char *str)
{
	// Malloc for new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	memset(new_node, 0, sizeof(struct Node));

	// Malloc for node char 
	int len = strlen(str);
	new_node->data = (char *)malloc(sizeof(char) * len);
	memset(new_node->data, 0, sizeof(char) * len);

	// Copying the data into node
    strncpy(new_node->data, str, len);
    new_node->next = NULL;

    return new_node;
}

bool isPalindrome(struct Node *head){
	
	 struct Node *temp = head;
	
	 // First we would calculate the number of nodes in the linked list
	 int count=0;
	 while(temp != NULL){
		   count += strlen(temp->data);
		   temp = temp->next;
	 }

	// Constructing the string based on linked list
	char *str = (char *)malloc(sizeof(char) * count);
	memset(str, 0, sizeof(char) * count);
	temp = head;
	int start_index = 0, end_index = 0;
	while(temp != NULL){
		  strcat(str, temp->data);
		  temp = temp->next;
	}
	
	// Checking if the string is palindrome or not
	int h = strlen(str)-1;
	int l = 0;
	while(h > l){
		  if(str[h] != str[l]){
		     return false;
		  }
		 h--;
		 l++;
	}

	return true;
}

int main()
{
    struct Node *head = newNode("a");
    head->next = newNode("bc");
    head->next->next = newNode("d");
    head->next->next->next = newNode("dcb");
    head->next->next->next->next = newNode("a");

	printList(head); 
    isPalindrome(head)? printf("true\n"):
                        printf("false\n");
 
    return 0;
}
