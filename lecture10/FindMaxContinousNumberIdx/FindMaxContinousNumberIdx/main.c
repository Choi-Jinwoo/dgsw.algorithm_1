#include <stdio.h>
/*
void main() {
	int arr[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };

	int maxContinousIdx = 0;
	int maxContinousCnt = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] == 1) {
			continue;
		}

		int isContinous = 0;
		arr[i] = 1;

		int continousCnt = 0; // 반복된 횟수
		int maxContinousCntLoop = 0; // 루프속 반복된 횟수의 최대

		for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++) {
			if (arr[j] == 1 && isContinous == 1) { // 연속되는 상황
				isContinous = 1;
				continousCnt++;
			}
			else if (arr[j] == 1 && isContinous == 0) { // 연속되지 않았지만 1인 상황
				isContinous = 1;
				continousCnt = 1;
			}
			else { // 0인상황
				isContinous = 0;
				continousCnt = 0;
			}

			if (continousCnt > maxContinousCntLoop) { // 반복문안의 최대 연속 숫자를 지정
				maxContinousCntLoop = continousCnt;
			}
		}

		if (maxContinousCnt < maxContinousCntLoop) {
			maxContinousCnt = maxContinousCntLoop;
			maxContinousIdx = i;
		}
		arr[i] = 0;
	}

	printf("%d\n", maxContinousIdx);
}
*/


void main() {
	int arr[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
	int count = 0;
	int prev_zero_index = -1;

	int max_count = 0;
	int max_index = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		// 현재 원소가 1인경우
		if (arr[i] == 1) {
			count++;
		}
		else { // 현재 원소가 0인경우
			// 현재 0을 포함해 이전 연속된 1의 개수를 count로 세팅
			count = i - prev_zero_index;
			
			// prev_zero_idex를 현재 인덱스로 업데이트
			prev_zero_index = i;
		}

		// 1의 개수가 이전 최대 1의 개수보다 크다면
		// max_count와 max_index를 업데이트
		if (count > max_count) {
			max_count = count;
			max_index = prev_zero_index;
		}
	}

	printf("%d\n", max_index);
}