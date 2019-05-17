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
bool check[1000][1000][11]; //(x,y,�ν����� �ƴ���) = �������� ���ݱ��� ������ ĭ ��
int dh[4] = { 0, 0, 1, -1 };
int dw[4] = { 1, -1, 0, 0 };
int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	//day : 1�̸� ������ �� �� ����
	//day : 0�̸� �㿡�� ���ѽ�
	//wait : 1�̸� ��ٸ� ����
	//wait : 0�̸� ������� ����
	deque<tuple<int, int, bool, bool, int, int> > q; //<X, Y, Day, wait, � �μ���, �� Nĭ ������>
	deque<tuple<int, int, bool, bool, int, int> > next; //<X, Y, Day, wait, � �μ���, �� Nĭ ������>
	check[0][0][0] = true;                          //�湮�ߴ��� �ƴ���  
	q.push_back(make_tuple(0,0,true,false,0,1));  //<X, Y, Day, wait, � �μ���, �� Nĭ ������>
	int min = 10000;
	while (!q.empty()) {
		int h, w, wall, dst; bool day, wait;
		tie(h, w, day, wait, wall, dst) = q.front(); q.pop_front();
		

		//���翡�� �� �� �ִ� 0�� ��� ����.
		for (int k = 0; k < 4; k++) {
			int nh = h + dh[k]; //next h
			int nw = w + dw[k]; //next w
			if (nh < 0 || nh >= N || nw < 0 || nw >= M) continue;
			
			//0���� �����̴� ���
			if (a[nh][nw] == 0 && check[nh][nw][wall] == 0) {
				check[nh][nw][wall] = true;
				q.push_back(make_tuple(nh, nw, !(day), false, wall, dst + 1));
			}
			//���� 1�� �����̴� ��� : ��ٸ��Ŷ� �������
			if (a[nh][nw] == 1 && check[nh][nw][wall] == 0 && day == true && wall < K) {
				check[nh][nw][wall] = true;
				q.push_back(make_tuple(nh, nw, !(day), false, wall + 1, dst + 1));
			}
			//��ٸ��� ���
			if (a[nh][nw] == 1 && check[nh][nw][wall] == 0 && day == false && wait == false && wall < K) {
				check[nh][nw][wall] = false;
				q.push_back(make_tuple(h, w, !(day), true, wall, dst + 1));
			}
		}
		if (h == N-1 && w == M-1) {
			if (dst > 0 && min > dst) {
				min = dst;
			}
		}
	}

	if (min == 10000) {
		printf("%d\n", -1);

	}
	else {
		printf("%d\n", min);
	}
	return 0;
}