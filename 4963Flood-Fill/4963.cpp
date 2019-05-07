/*
2019-05-05
장환석

문제
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.

한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 지도는 바다로 둘러쌓여 있으며, 지도 밖으로 나갈 수 없다.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 섬의 개수를 출력한다.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int w, h;
int a[50][50];
int group[50][50];
int gnum;
int island[50 * 50];
//            우 좌  상  하 우상 우하 좌상 좌하
int dx[8] = { 1, -1, 0 , 0, 1 , 1, -1, -1 };
int dy[8] = { 0, 0,  1, -1, 1,  -1, 1,  -1};

void dfs(int x, int y, int g) { // g means group
	//지정된 group을 지정
	group[x][y] = g;
	int nx=0, ny=0; //next_x,_y
	for (int k = 0; k < 8; k++) {
		nx = x + dx[k];
		ny = y + dy[k];
		//벗어난 영역은 제외
		if (nx < 0 || nx >= h) continue;
		if (ny < 0 || ny >= w) continue;
		//벗어나지 않은 모든 영역에 대해서 섬이있는지 그리고 그룹이 정해졌는지 확인
		if (a[nx][ny] == 1 && group[nx][ny] == 0) {
			dfs(nx, ny, g);
		}
	}
}


int main(void) {

	while (true) {
		
		//테스트 케이스 별 rwo col 입력
		scanf("%d %d", &w, &h);

		//종료 처리
		if (w == 0 && h == 0) break;

		//row col에 해당하는 입력 받아오기 땅은 1, 바다는 0
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		gnum = 0;
		//dfs 알고리즘으로 연결된 요소를 그룹으로 묶는다. 
		//모든 땅에 대해서 dfs를 시작하기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 1 && group[i][j] == 0) {
					dfs(i, j, ++gnum);
				}
			}
		}

		printf("%d\n", gnum);

		//초기화
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				a[i][j] = 0;
				group[i][j] = 0;
			}
		}
	}
	
	return 0;
}