/*
2019-04-05
장환석

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

*/

#include <iostream>
#include <cstdio>
using namespace std;
int N = 0, M = 0, index;

int go(int arr[], int index) {
	if (index == M) {
		for (int i = 0; i < M;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return 0;
	}
	else {
		for (int value = 1; value <= N; value++) {
			if (index == 0){
				arr[0] = value;
				go(arr, index + 1);
			}
			else {
				if (arr[index - 1] <= value) {
					arr[index] = value;
					go(arr, index + 1);
				}
			}
		}
	}
}

int main(void) {
	int arr[9] = { 0, 0,0,0,0,0,0,0,0};
	scanf_s("%d %d", &N, &M); //백준에서는 scanf_s를 사용하지  못하나?
	go(arr, 0);
	return 0;
}