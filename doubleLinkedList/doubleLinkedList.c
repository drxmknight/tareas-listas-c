#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct dlist {
	struct node *head;
};

void initStack(struct dlist *list);
void push(struct dlist *list, int value);
int pop(struct dlist *list);
void freeList(struct dlist *list);
void printList(struct dlist list);



int main()
{
	int option = 1;
	int value = 0;
	struct dlist doublelinkedlist;
	initStack(&doublelinkedlist);

	printf("\nBuild a List!");
	while (option != 0) {
		printf("\n----------------\n");
		printf("(1) Push\n");
		printf("(2) Pop\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Select an option: ");
		scanf("%d", &option);

		if (option == 1) {
			printf("Insert a value: ");
			scanf("%d", &value);
			push(&doublelinkedlist, value);
		}

		if (option == 2) {
			printf("value: %d\n", pop(&doublelinkedlist));
		}

		if (option == 3) {
			printList(doublelinkedlist);
		}
	}

	freeList(&doublelinkedlist);
	return 0;
}

void initStack(struct dlist *list)
{
	list->head = NULL;
}

void push(struct dlist *list, int value)
{
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = value;
	newnode->prev = NULL;
	newnode->next = list->head;
	if(list->head != NULL)
		list->head->prev = newnode;
	list->head = newnode;
}

int pop(struct dlist *list)
{
	if (list->head == NULL)
		return -1;
	int result = list->head->data;
	struct node *temp = list->head;
	list->head = temp->next;
	if (list->head != NULL)
		list->head->prev = NULL;
	free(temp);
	return result;
	
}

void freeList(struct dlist *list) 
{
	if (list->head == NULL)
		return;
	struct node *temp = list->head;
	while (list->head != NULL) {
		list->head = temp->next;
		free(temp);
		temp = list->head;
	}
	printf("Stack cleaned!\n");
}

void printList(struct dlist list) 
{
	struct node *temp = list.head;
	if (temp == NULL) {
		printf("the list is empty!\n");
		return;
	}
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
} 