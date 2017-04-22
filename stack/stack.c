#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
};

struct list{
	struct node* head;
};

void initStack(struct list *stack);
void push(struct list *stack, int value);
int pop(struct list *stack);
void freeStack (struct list *stack);
void printStack(struct list stack);

int main() 
{
	int option = 1;
	int value = 0;
	struct list myStack;
	initStack(&myStack);

	printf("\nBuild a stack!");
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
			push(&myStack, value);
		}

		if (option == 2) {
			printf("value: %d\n", pop(&myStack));
		}

		if (option == 3) {
			printStack(myStack);
		}
	}
	freeStack(&myStack);
	return 0;
}

void initStack(struct list *stack)
{
	stack->head = NULL;
}

void push(struct list *stack, int value)
{
	struct node *newnode = malloc(sizeof(struct node));
	newnode->value = value;
	newnode->next = stack->head;
	stack->head = newnode;
}

int pop(struct list *stack) 
{
	if (stack->head == NULL)
		return -1;
	int val = stack->head->value;
	struct node *temp = stack->head;
	stack->head = temp->next;
	free(temp);
	return val;
}

void freeStack (struct list *stack)
{
	if (stack->head == NULL)
		return;
	
	struct node *temp = stack->head;
	while (stack->head != NULL) {
		stack->head = temp->next;
		free(temp);
		temp = stack->head;
	}
	printf("Stack cleaned!\n");
}

void printStack(struct list stack)
{
	struct node *temp = stack.head;
	if (temp == NULL) {
		printf("the stack is empty!\n");
		return;
	}
	while (temp != NULL) {
		printf("%d\n", temp->value);
		temp = temp->next;
	}
} 