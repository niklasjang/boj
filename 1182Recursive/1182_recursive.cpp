/*
2019-00-00
장환석

문제
N개의 정수로 이루어진 수열이 있을 때, 길이가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

*/


#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;
int set[MAX];
int N, S;


int go(int depth, int sum) {
	if (depth == N) {
		//마지막에서 OXXXXX인지 OOOXXX인지 확인하면 된다. ex) 2XXXXX / 2 -2 2 XXX 둘 다 합은 2
		if (sum == S) {
			return 1;
		}
		else {
			return 0;
		}
	}
	//다시 call 해야하는 경우
	int count = 0;
	count += go(depth + 1, sum + set[depth]);
	count += go(depth + 1, sum);
	return count;
}

int main(void) {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> set[i];
	}
	if (S == 0) {
		cout << go(0, 0) -1 << "\n";

	}
	else {
		cout << go(0, 0) << "\n";

	}

	return 0;
}