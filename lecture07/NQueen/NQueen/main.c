#include <stdio.h>
#include <stdlib.h>

void queens(int);
int promising(int);
int n;
int col[255] = { 0 };

void main() {
	printf("How many Queens? ");
	scanf_s("%d", &n);
	queens(0);
}

void printResult() {
	int i;
	printf("result : ");
	for (i = 1; i <= n; i++) {
		printf("%d ", col[i]);
	}
	exit(1);
}

void queens(int i) {
	int j;
	if (promising(i)) {
		if (i == n) {
			printResult();
		}
		else {
			for (j = 1; j <= n; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
		}
	}
}

int promising(int i) {
	int k = 1, promising = 1;
	while (k < i && promising) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k)) {
			promising = 0;
		}
		k++;
	}

	return promising;
}