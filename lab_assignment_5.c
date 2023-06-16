/*
Miguel J Chevalier
COP3502
6/9/23
Lab Assignment 4
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node *tmp = head;
	if (tmp == NULL)
		return 0;
	int i = 0;
	while (tmp != NULL) {
		i++;
		tmp = tmp->next;
	}

	return i;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node *tmp = head;
	if (head == NULL)
		return NULL;
	char* string = (char *) malloc((length(head))*sizeof(char) + 1);
	for (int i = 0; i < length(head) + 1; i++) {
		if (i + 1 == length(head) + 1) {
			string[i] = '\0';
			break;
		}
		string[i] = tmp->letter;
		tmp = tmp->next;
	}

	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *newNode = (node *) malloc(sizeof(node));
	newNode->next = NULL;
	newNode->letter = c;

    node *temp = *pHead;

    if(*pHead == NULL)
		*pHead = newNode;
    else {
		while(temp->next != NULL)
			temp = temp->next;

		temp->next = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* tmp = (*pHead);
	if ((*pHead) == NULL) {
		return;
	}
	while (tmp != NULL) {
		node *next = tmp->next;
		free(tmp);
		tmp = next;
	}
	(*pHead) = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}