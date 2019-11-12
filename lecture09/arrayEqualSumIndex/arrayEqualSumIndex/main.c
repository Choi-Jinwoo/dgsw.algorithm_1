#include <stdio.h>

void main() {
	int arr[] = { 0, -3, 5, -4, -2, 3, 1, 0 };
	int result[100];
	int resultCnt = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		int preSum = 0;
		int nextSum = 0;
		for (int j = 0; j < i; j++) {
			preSum += arr[j];
		}
		for (int j = i + 1; j < sizeof(arr) / sizeof(arr[0]); j++) {
			nextSum += arr[j];
		}
		
		if (preSum == nextSum) {
			result[resultCnt++] = i;
		}
	}

	for (int i = 0; i < resultCnt; i++) {
		printf("%d\n", result[i]);
	}
}