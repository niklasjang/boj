/*
2019-04-05
장환석

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int N = 0, M = 0, index;
int arr[9];
int num[9];
bool color[9];

void go(int index) {
	if (index == M) {
		for (int i = 0; i < M;i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
	}
	else {
		for (int value = 0; value < N; value++) {
			if (color[value] == true) continue;
			if (value != 0 && color[value - 1] == false && arr[value - 1] == arr[value]) continue;
			if (index != 0 && num[index - 1] > arr[value]) continue;
			color[value] = true;
			num[index] = arr[value];
			go(index + 1);
			color[value] = false;
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M); //백준에서는 scanf_s를 사용하지  못하나?
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, &arr[N]);
	go(0);
	return 0;
}