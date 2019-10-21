#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b) {
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
	int i, w;
	int K[n + 1][W + 1]; //메모이제이션(컴파일러 오류 -> 동적할당)
	for (i = 0; i <= n; i++) { //보석별로 확인
		for (w = 0; w <= W; w++) { //무게별 확인(가방 무게 까지 반복)
			if (i == 0 || W == 0) { //첫번째 보석이거나 무게가 0이면 0으로 초기화
				K[i][w] = 0;
			}
			else if (wt[i - 1] <= w) { //현재 보석의 무게 <= 가방 무게
				K[i][w] = Max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); //현재 보석까지의 최고 가치를 구함
					//현재 보석의 가치 + 이전 보석까지의 (무게-현재보석무게)의 최고 가치, 이전 보석까지의 최고 가치
			}
			else { //남는 무게가 없을때
				K[i][w] = K[i - 1][w]; //이전 보석까지의 최고 무게
			}
		}
	}

	return K[n][W];
}

void main() {
	int val[] = { 60, 100, 120 }; //보석 가치
	int wt[] = { 10, 20, 30 }; //보석 무게
	int W = 50; //가방 무게
	int n = sizeof(val) / sizeof(val[0]);
	printf("최댓값 : %d\n", knapSack(W, wt, val, n));
}