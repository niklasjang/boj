/*
2019-05-06
장환석
문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>


int N, M;
int a[100][100];
using namespace std;
queue<pair<int,int>> q;
int check[100][100];
		//   상 하 좌 우
/*
	|
----+---------------> x 축
	|(0,0) (0,1),(0,2)
	|(1,0) (1,1),(1,2)
	y축
*/
int dx[4] = { 0,0,-1,+1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int i, int j, int &count) {
	check[i][j] = count;
	//printf("push %d %d\n", i, j);
	q.push(make_pair(i,j));
	while (!q.empty()) {
		pair<int,int> curr = q.front(); q.pop();
		int nx = 0, ny =0;
		for (int k = 0; k < 4; k++) {
			nx = curr.first + dx[k];
			if (nx < 0 || nx >= N) continue;
			ny = curr.second + dy[k];
			if (ny < 0 || ny >= M) continue;
			if (a[nx][ny] == 1 && check[nx][ny] == 0) {
				check[nx][ny] = check[curr.first][curr.second]+1;
				//printf("push %d\n",a[nx][ny]);
				q.push(make_pair(nx, ny));
			}
		}
	}
}


int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(a[i][j] == 1 && check[i][j] == 0) dfs(i, j, ++count);
		}
	}

	printf("%d",check[N - 1][M - 1]);

	return 0;
}