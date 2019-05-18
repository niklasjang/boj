/*
2019-05-17
장환석


문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 한 칸에서 다른 칸으로 이동하려면, 두 칸이 인접해야 한다. 두 칸이 변을 공유할 때, 인접하다고 한다.

각각의 벽에 대해서 다음을 구해보려고 한다.

벽을 부수고 이동할 수 있는 곳으로 변경한다.
그 위치에서 이동할 수 있는 칸의 개수를 세어본다.
입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다.

출력
맵의 형태로 정답을 출력한다. 원래 빈 칸인 곳은 0을 출력하고, 벽인 곳은 이동할 수 있는 칸의 개수를 10으로 나눈 나머지를 출력한다.
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <stack>
#include <tuple>
using namespace std;
int N, M;

int a[1001][1001];
bool check[1001][1001];
int result[1001][1001];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(int h, int w) {
	queue<tuple<int, int, int> > q;       // X, Y, 지금까지 0이 몇개?
	stack<tuple<int, int, int> > stk;

	check[h][w] = true;
	q.push(make_tuple(h, w, 0));

	while (!q.empty()) {
		tuple<int, int, int> curr = q.front(); q.pop();
		int x = curr.first;
		int y = curr.second;
		for (int k = 0; k < 4; k++) {
			int nh = x + dx[k];
			int nw = y + dy[k];
			if (nh < 0 || nw < 0 || nh >= N || nw >= M) continue;

			if (a[nh][nw] == 0 && check[nh][nw] == false) {
				check[nh][nw] = true;
				q.push(make_pair(nh,nw))
			}
		}
	}
}

int main(void) {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
			if (a[i][j] == 1) {
				result[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			bfs(i, j);
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d", (room[i][j]) % 10);
		}
		printf("\n");
	}
	return 0;
}