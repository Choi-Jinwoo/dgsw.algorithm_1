#include <stdio.h>
#define NUM 10
#define MAX 100
#define MIN 0

void ranking() {
	int a[] = { 56, 25, 67, 88, 100, 61, 55, 67, 76, 56 };
	int rank[NUM] = { 0 };

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		for (int j = 0; j < sizeof(a) / sizeof(a[0]); j++) {
			if (a[i] < a[j]) {
				rank[i]++;
			}
		}
	}

	for (int i = 0; i < sizeof(rank) / sizeof(rank[0]); i++) {
		printf("%d : %d\n", a[i], rank[i] + 1);
	}
}

void ranking_2() {
	int a[] = { 56, 25, 67, 88, 100, 61, 55, 67, 76, 56 };
	int i, rank[MAX + 2] = { 0 };
	
	for (i = 0; i < NUM; i++) {
		rank[a[i]]++;
	}

	rank[MAX + 1] = 1;
	for (i = MAX; i >= MIN; i--) {
		rank[i] = rank[i] + rank[i + 1];
	}

	for (i = 0; i < NUM; i++) {
		printf("%6d%6d\n", a[i], rank[a[i] + 1]);
	}
}

#define Num 10
#define Max 36
#define Min -20
#define Bias 1-(Min)

void ranking_3() {
	int a[] = { -3, 2, 3, -1, -2, -6, 2, -1, 1, 5 };
	int i, rank[Max + Bias + 1];

	for (i = Min + Bias; i <= Max; i++) {
		rank[i] = 0;
	}

	for (i = 0; i < Num; i++) {
		rank[a[i] + Bias]++;
	}
	rank[0] = 1;
	for (i = Min + Bias; i <= Max + Bias; i++) {
		rank[i] = rank[i] + rank[i - 1];
	}

	printf("점수 순위\n");
	for (i = 0; i < Num; i++) {
		printf("%6d%6d\n", a[i], rank[a[i] + Bias - 1]);
	}
}


void main() {
	ranking_3();
}