/*
2019-05-08
장환석

숨바꼭질
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	52572	14518	8972	24.719%
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int N, K;
int check[200000]; //0은 방문하지 않음. 시작은 1 다음 step은 2 ~~~ 총 step 갯수는 최대값 -1
int bfs(int start) {
	queue<int> q;
	check[start] = 1;
	q.push(start);
	int temp = 0;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		temp = curr * 2;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				check[temp] = check[curr] + 1;
				q.push(temp);
			}
		}
		temp = curr + 1;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				check[temp] = check[curr] + 1;
				q.push(temp);
			}
		}
		temp = curr - 1;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				check[temp] = check[curr] + 1;
				q.push(temp);
			}
		}
	}
	return -1;
}

int main(void) {
	scanf("%d %d", &N, &K);
	bfs(N);
	printf("%d\n",check[K]-1);
	return 0;
}