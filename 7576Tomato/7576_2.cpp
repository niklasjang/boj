/*
2019-03-21
장환석

문제
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.



창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N 은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

출력
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
*/

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
int M, N;
int a[1000][1000];

//           상 하 좌 우
int dh[] = { -1,1, 0, 0 };
int dw[] = { 0,0, -1, 1 };

queue<pair<int, int>> q;
int day = 0;

void bfs(void) {
	int nw = 0, nh = 0;
	while (!q.empty()) {
		
		//하나 뽑고 
		pair<int,int> curr = q.front(); q.pop();
		//사방 넣고
		for (int k = 0; k < 4; k++) {
			//index 예외처리
			nh = curr.first+ dh[k];
			if (nh < 0 || nh >= N) continue;
			nw = curr.second+ dw[k];
			if (nw < 0 || nw >= M) continue;
			//안익었으면 익히고 day++
			if (a[nh][nw] == 0) {
				a[nh][nw] = a[curr.first][curr.second] + 1;
				if (day < a[curr.first][curr.second] + 1) day = a[curr.first][curr.second] + 1;
				q.push(make_pair(nh, nw));
			}
		}

		//다시 뽑고
	}

}


int main(void) {

	bool noZero = true;  //모든 토마토가 익어있는 상태 : 0이 하나도 없는 상태이면 false 아니면 true
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0){
				noZero = false;
			}
		}
	}

	//모든 토마토가 익어있는 상태면
	if (noZero) {
		printf("0\n");
		return 0;
	}
	//전체를 돌면서 step1에서 안익은 토마토를 q에 다 넣는다
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();

	//익지 못하는 경우가 있으면
	bool isAllNotRippable = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 0) isAllNotRippable = true;
		}
	}
	if (isAllNotRippable) {
		printf("-1\n");
	}
	else {
		printf("%d\n", day-1);
	}
	return 0;
}