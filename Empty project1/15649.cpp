/*
2019-04-01
장환석

문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.


*/

#include <iostream>
#include <cstdio>
using namespace std;
int N = 0, M = 0, index;
int arr[9];
bool color[9];

void go(int index) {
	if (index == M) {
		for (int i = 0; i < M;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else {
		for (int value = 1; value <= N; value++) {
			if (color[value] == true) continue; //해당 숫자를 사용했었으면 continue
			color[value] = true; //사용 안했으면 사용할 것이라서 true로 바꾸고
			arr[index] = value; //arr[index++]에 처음부터 중복이 없는 순열로 뽑을 것들을 저장해준다.
			go(index + 1); //arr안에 index번째까지 골랐으면 다음 call을 한다.
			color[value] = false; //call이 끝나면 #37번째 줄에서 사용했던 값은 다음 for문에서는 사용하지 않은 것으로 생각해야하기기 때문에(++된 value 값부터 arr[index]에 들어갈 수 있는지 확인하기 때문)
			//check[value] = false로 한다.
		}
	}
}

int main(void) {
	scanf_s("%d %d", &N, &M); //백준에서는 scanf_s를 사용하지  못하나?
	go(0);
	return 0;
}