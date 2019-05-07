/*
2019-05-06
��ȯ��
����
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����. �̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.

���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

�Է�
ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����. ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.

���
ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�. �׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.
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
		//   �� �� �� ��
/*
	|
----+---------------> x ��
	|(0,0) (0,1),(0,2)
	|(1,0) (1,1),(1,2)
	y��
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