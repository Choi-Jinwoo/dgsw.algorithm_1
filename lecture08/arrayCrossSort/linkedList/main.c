#include <stdlib.h>
#include <stdio.h>

void main() {
	int arr[100];
	int cnt = 0;
	while (1) {
		int input;
		scanf_s("%d", &input);
		if (input == 0) {
			break;
		}
		arr[cnt] = input;
		cnt++;
	}
	
	for (int i = 1; i < cnt; i += 2) {
		if (arr[i - 1] > arr[i]) {
			int temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
		}
		if (i + 2 > cnt - 1) {
			break;
		}
		if (arr[i + 1] > arr[i]) {
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}

	for (int i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}
}