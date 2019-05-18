/*
2019-05-17
��ȯ��


����
N��M�� ��ķ� ǥ���Ǵ� ���� �ִ�. �ʿ��� 0�� �̵��� �� �ִ� ���� ��Ÿ����, 1�� �̵��� �� ���� ���� �ִ� ���� ��Ÿ����. �� ĭ���� �ٸ� ĭ���� �̵��Ϸ���, �� ĭ�� �����ؾ� �Ѵ�. �� ĭ�� ���� ������ ��, �����ϴٰ� �Ѵ�.

������ ���� ���ؼ� ������ ���غ����� �Ѵ�.

���� �μ��� �̵��� �� �ִ� ������ �����Ѵ�.
�� ��ġ���� �̵��� �� �ִ� ĭ�� ������ �����.
�Է�
ù° �ٿ� N(1 �� N �� 1,000), M(1 �� M �� 1,000)�� �־�����. ���� N���� �ٿ� M���� ���ڷ� ���� �־�����.

���
���� ���·� ������ ����Ѵ�. ���� �� ĭ�� ���� 0�� ����ϰ�, ���� ���� �̵��� �� �ִ� ĭ�� ������ 10���� ���� �������� ����Ѵ�.
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
	queue<tuple<int, int, int> > q;       // X, Y, ���ݱ��� 0�� �?
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