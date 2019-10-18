#include <stdio.h>

int len[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int price[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

int getBenefit(int n) {
	if (n < 2) return price[n - 1];

	int maxBenefit = 0;
	for (int i = 0; i < (n / 2) + 1; i++) {
		int last = len[n - 1] - i;
		int lastPrice = 0; 
		int originPrice = 0;
		if (last > 0) {
			lastPrice = price[last - 1];
		}
		if (i > 0) {
			originPrice = price[i - 1];
		}
		if (maxBenefit < lastPrice + originPrice) {
			maxBenefit = lastPrice + originPrice;
		}
	}
	return maxBenefit;
}

int recursiveGetBenefit(int n) {
	if (price[n] != 0) 
		return price[n];
	else {
		int max = 0;
		for (int i = 1; i <= n / 2; i++) {
			int a = recursiveGetBenefit(n - i) + recursiveGetBenefit(i);
			if (max < a)
				max = a;
		}
		price[n] = max;
		return max;
	}
}

void main() {
	for (int i = 0; i < 11; i++) {
		printf("%d\n", recursiveGetBenefit(i));
	}
	
}