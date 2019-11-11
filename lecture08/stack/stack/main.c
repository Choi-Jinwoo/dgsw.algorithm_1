#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * link;
}node;

node * top = NULL;

void push(int input) {
	node * newnode = (node*)malloc(sizeof(node));
	newnode->data = input;
	newnode->link = NULL;
	
	if (top == NULL) {
		top = newnode;
	}
	else {
		newnode->link = top;
		top = newnode;
	}
}

int pop() {
	node * delnode;
	if (top == NULL) {
		printf("stack underflow");
		return 0;
	}
	else {
		delnode = top;
		int data = delnode->data;
		top = top->link;
		free(delnode);
		return data;
	}
}

void main() {
	push(3);
	push(4);
	printf("%d", pop());
	printf("%d", pop());
	printf("%d", pop());
	push(5);
	printf("%d", pop());
	printf("%d", pop());
}