/*
2019-00-00
��ȯ��

*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int N, M;
int a[101][101];
int check[101][101]; //�󸶳� ���� ���� �μ��� �Դ����� ī��Ʈ, �湮���� �ʾ����� -1
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

	check[0][0] = 0; //�湮, 0�� �μ��� ��
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
				//���� �湮�� ���� ���̸� 1 �߰� �ƴϸ� �״��
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
				//�̹� �湮�� ���̸� ������ ���̶� ���翡�� ���� ���̶� �񱳿��� ���� �ɷ� ����
				if (a[nh][nw] == 0) {
					if (check[nh][nw] > check[h][w]) {
						check[nh][nw] = check[h][w];
						q.push_front(make_pair(nh, nw)); //������ �湮�ߴ� ���̶� ������ ���� ������ �湮�ϸ� q�� �־���� �Ѵ�.
					}
				}
				else {
					if (check[nh][nw] > check[h][w] + a[nh][nw]) {
						check[nh][nw] = check[h][w] + a[nh][nw];
						q.push_back(make_pair(nh, nw)); //������ �湮�ߴ� ���̶� ������ ���� ������ �湮�ϸ� q�� �־���� �Ѵ�.
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