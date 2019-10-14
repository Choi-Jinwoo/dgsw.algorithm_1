#include <stdio.h>

void main() {
	int a[] = { 35, 25, 56, 78, 48, 66, 71, 73, 80, 90, 0, 73, 35, 65, 100, 78, 80, 85, 35, 50 };
	int stat[11] = { 0 };
	int arr[128] = { 0 };
	int mode = 0;

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		stat[a[i] / 10]++;
		arr[a[i]]++;
	}

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] > arr[mode]) {
			mode = i;
		}
	}

	for (int i = 0; i < sizeof(stat) / sizeof(stat[0]); i++) {
		printf("%d : %d\n", i * 10, stat[i]);
	}

	printf("ÃÖºó°ª : %d\n", mode);
}