/*
2019-05-16
��ȯ��

*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <deque>
#include <tuple>
using namespace std;

int N, M, K;
int a[1000][1000];
int check[1000][1000][11]; //(x,y,�ν����� �ƴ���) = �������� ���ݱ��� ������ ĭ ��
int dh[4] = { 0, 0, 1, -1 };
int dw[4] = { 1, -1, 0, 0 };

int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	queue<tuple<int, int, int> > q; //������ �湮�� ��ǥ�� h,w �� push��
	queue<tuple<int, int, int> > next;
	check[0][0][0] = 1;      //(h,w,�ν����� �ƴ���) = �������� ���ݱ��� ������ ĭ ��
	q.push(make_tuple(0, 0, 0)); // ( ������ �湮�� h ��ǥ, ������ �湮�� w ��ǥ, �ο����� �ƴ���)
	while (!q.empty()) {
		int h, w, p;
		tie(h, w, p) = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			
			int nh = h + dh[k]; //next h
			int nw = w + dw[k]; //next w
			if (nh < 0 || nh >= N || nw < 0 || nw >= M) continue;

			//4���� ���� �� �� ���⸸  �����ϸ� �� ���� ���⿡ ��� ����ǰ�

			//�����ΰ��� ���
			//������ �湮�� ��Ұ� ���̰�, �� ���� �湮�� ���� ������ (������ �湮�ߴ� p�� ���ؼ�)
			//0���� �� ��, 0���� ������ 1���� ������ ��� ó��
			if (a[nh][nw] == 0 && check[nh][nw][p] == 0) {
				check[nh][nw][p] = check[h][w][p] + 1;
				q.push(make_tuple(nh, nw, p));
			}

			//������ ���� ���
			//���ݱ��� �μ� ���� ����, ���� �ְ� , �� ���� �湮���� �ʾ�����
			//1�� ���� ���� 0���� ���� ��츸 ó��
			if (p <= K-1 && a[nh][nw] == 1 && check[nh][nw][p + 1] == 0) {
				check[nh][nw][p+1] = check[h][w][p] + 1;
				q.push(make_tuple(nh, nw, p + 1));
			}
			
		}
	}
	
	/*for (int k = 0; k <= K; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("(%d) ", check[i][j][k]);
			}
			puts("");
		}

		puts("");
	}*/
	

	


	int result = 10000;
	for (int i = 0; i <= K; i++) {
		//printf("check[N - 1][M - 1][i] : %d\n", check[N - 1][M - 1][i]);
		if (check[N - 1][M - 1][i] > 0 && result > check[N - 1][M - 1][i]) {
			result = check[N - 1][M - 1][i];
		}
	}

	if (result == 10000) {
		printf("-1");
	}
	else {
		printf("%d", result);
	}

	return 0;
}