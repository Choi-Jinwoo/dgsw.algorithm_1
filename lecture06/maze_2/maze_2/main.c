#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType * s) {
	s->top = -1;
}

int is_empty(StackType * s) {
	return (s->top == -1);
}

int is_full(StackType * s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType * s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType * s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	}
	else return s->data[(s->top)--];
}

char maze[6][6] = {
	{ '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '1', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '1' },
	{ '1', '0', '1', '0', '1', '1' },
	{ '1', '0', '1', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1' },
};

void main() {
	StackType s;
	init_stack(&s);
	
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

}