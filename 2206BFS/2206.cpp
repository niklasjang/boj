/*
2019-05-15
장환석

*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <deque>
#include <tuple>
using namespace std;

int N, M;
int a[1000][1000];
int check[1000][1000][2]; //(x,y,부쉈는지 아닌지) = 원점에서 지금까지 지나온 칸 수
int dh[4] = { 0, 0, 1, -1 };
int dw[4] = { 1, -1, 0, 0 };

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	
	queue<tuple<int,int,int> > q; //다음에 방문할 좌표의 h,w 가 push됨

	check[0][0][0]= 1;      //(h,w,부쉈는지 아닌지) = 원점에서 지금까지 지나온 칸 수
	q.push(make_tuple(0,0,0)); // ( 다음에 방문할 h 좌표, 다음에 방문할 w 좌표, 부웠는지 아닌지)
	while (!q.empty()) {
		int h, w, p; 
		tie(h,w,p) = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int nh = h + dh[k]; //next h
			int nw = w + dw[k]; //next w
			if (nh < 0 || nh >= N || nw < 0 || nw >= M) continue;
			
			//4가지 방향 중 한 방향만  생각하면 네 가지 방향에 모두 적용되고

			//방으로가는 경우
			//다음에 방문할 장소가 방이고, 그 방을 방문한 적이 없으면 (이전에 방문했던 p에 대해서)
			//0으로 올 때, 0에서 오는지 1에서 오는지 모두 처리
			if (a[nh][nw] == 0 && check[nh][nw][p] == 0) { 
				check[nh][nw][p] = check[h][w][p] + 1;
				q.push(make_tuple(nh, nw, p));
			}

			//벽으로 가는 경우
			//지금까지 부순 벽이 없고, 벽이 있고 , 그 벽을 방문하지 않았으면
			//1로 오는 경우는 0에서 오는 경우만 처리
			if (p == 0 && a[nh][nw] == 1 && check[nh][nw][p+1] == 0) {
				check[nh][nw][1] = check[h][w][p] + 1;
				q.push(make_tuple(nh, nw, p+1));
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("(%d) ", check[i][j][0]);
		}
		puts("");
	}

	puts("");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("(%d) ", check[i][j][1]);
		}
		puts("");
	}*/


	if (check[N - 1][M - 1][0] != 0 && check[N - 1][M - 1][1] != 0) {
		printf("%d ", check[N-1][M-1][1] > check[N-1][M - 1][0] ? check[N-1][M - 1][0] : check[N-1][M - 1][1]);
	}
	else if (check[N - 1][M - 1][0] != 0) {
		printf("%d ", check[N - 1][M - 1][0]);
	}
	else if (check[N - 1][M - 1][1] != 0) {
		printf("%d ", check[N - 1][M - 1][1]);
	}
	else {
		printf("%d\n", -1);
	}

	return 0;
}