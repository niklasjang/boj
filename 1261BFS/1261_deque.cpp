/*
2019-00-00
장환석

*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int N, M;
int a[101][101];
int check[101][101]; //얼마나 많은 벽을 부수고 왔는지를 카운트, 방문하지 않았으면 -1
int dh[4] = { 0, 0, 1, -1 };
int dw[4] = { 1, -1, 0, 0 };
int main(void) {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	memset(check, -1, sizeof(check));

	deque<pair<int, int> > q;

	check[0][0] = 0; //방문, 0개 부수고 옴
	q.push_front(make_pair(0, 0));
	int index = 0;
	while (!q.empty()) {
		pair<int, int> curr = q.front(); q.pop_front();
		int h = curr.first; int w = curr.second;
		for (int k = 0; k < 4; k++) {
			int nh = h + dh[k]; //next h
			int nw = w + dw[k]; //next w
			if (nh < 0 || nh >= N) continue;
			if (nw < 0 || nw >= M) continue;
			if (check[nh][nw] == -1) {
				//다음 방문할 곳이 벽이면 1 추가 아니면 그대로
				if (a[nh][nw] == 0) {
					check[nh][nw] = check[h][w] + a[nh][nw];
					q.push_front(make_pair(nh, nw));
				}
				else {
					check[nh][nw] = check[h][w] + a[nh][nw];
					q.push_back(make_pair(nh, nw));
				}
			}
			else {
				//이미 방문한 곳이면 기존의 값이랑 현재에서 가는 값이랑 비교에서 작은 걸로 저장
				if (a[nh][nw] == 0) {
					if (check[nh][nw] > check[h][w]) {
						check[nh][nw] = check[h][w];
						q.push_front(make_pair(nh, nw)); //기존에 방문했던 점이라도 현재의 점을 지나서 방문하면 q에 넣어줘야 한다.
					}
				}
				else {
					if (check[nh][nw] > check[h][w] + a[nh][nw]) {
						check[nh][nw] = check[h][w] + a[nh][nw];
						q.push_back(make_pair(nh, nw)); //기존에 방문했던 점이라도 현재의 점을 지나서 방문하면 q에 넣어줘야 한다.
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", check[i][j]);
		}
		puts("");
	}
	*/
	printf("%d ", check[N - 1][M - 1]);


	return 0;
}