#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* t;
	t = head;
	int len = 0;
	while (t->next != NULL){
		len++;
		t=t->next;
	}
	return len;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* t;
	t = head;
	char temp;
	char* parse=malloc(sizeof(char) * (length(head)));
	for(int i = 0; i < (length(head)+1); i++){
		temp = t->letter;
		parse[i] = temp;		
		t=t->next;
	}
	return parse;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *t;
	node *insert;
	insert=(node *) malloc(sizeof(node));
	insert->letter = c;
	insert->next = NULL;
	if(*pHead==NULL)
		*pHead = insert;
	else
	{
		t = *pHead;
		while(t->next != NULL)
			t=t->next;
		t->next = insert;
	}\
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	//node *del=*pHead;
	node*temp;
	while(*pHead!=NULL){
		temp=(*pHead)->next;
		free(*pHead);
		*pHead=temp;
	}
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