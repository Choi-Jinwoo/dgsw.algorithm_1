#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct Node * link;
} Node;

Node * front = NULL;
Node * rear = NULL;

void enqueue(int input) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = input;
	newNode->link = NULL;
	if (front == NULL) {
		front = newNode;
		rear = newNode;
	}
	else {
		rear->link = newNode;
		rear = newNode;
	}
}

void dequeue() {
	if (front == NULL) {
		printf("queue underflow");
		return;
	}

	Node * delNode = front;
	front = front->link;
	/*if (front == NULL) {
		front = NULL;
		rear = NULL;
	}*/
	free(delNode);
}

void printq() {
	Node * p = front;
	while (p) {
		printf("%d\n", p->data);
		p = p->link;
	}
}

void main() {
	enqueue(3);
	enqueue(4);
	printq();
	dequeue();
	printq();
	dequeue();
}