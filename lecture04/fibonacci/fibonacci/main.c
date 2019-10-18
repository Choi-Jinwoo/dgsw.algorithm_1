#include <stdio.h>
#define MAX_SIZE 100

int fibonacci(int n) {
	static int arr[MAX_SIZE]; //메모이제이션
	if (n < 2) return n;
	if (arr[n] > 0) return arr[n];
	else return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

//메모이제이션 X
int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	return dp(x - 1) + dp(x - 2);
}

void main() {
	int num = 10;
	int result;

	result = fibonacci(num);
	printf("%d번째 피보나치 수열 값: %d\n", num, result);
}