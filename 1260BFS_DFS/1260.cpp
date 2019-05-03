#include <iostream>
#include <queue>
using namespace std;
int N, M;
int node[1000 + 1];
bool check[1000 + 1];
int edge[1000 + 1][1000 + 1];

void dfs(int x) {
	check[x] = true; //�湮�ߴ��� ���ߴ����� ����������. ���� ���� �ƴ�
	printf("%d ", x);
	for (int i = 1; i < N + 1; i++) {//��� ��忡 ���ؼ�
		if (edge[x][i] == 1 && check[i] == false) {//���� ��忡�� �ٸ� ���� ���� ���� �ְ�, �� ���� �Ȱ�����
			dfs(i);
		}
	}
}

void bfs(int x) { //���⼱ false�� �湮�� ����
	queue<int> q;
	check[x] = false;
	q.push(x);
	while (!q.empty()) {
		x = q.front(); q.pop(); //q�� front�� ���� �� ���� Ž��.
		printf("%d ", x);
		for (int i = 1; i < N + 1; i++) {//�̹� x�� ������ ��� ��带 �� q�� �ִ´�.
			//�ش� ��带 �湮�� �� q�� ������ ���ǿ��� ������ ��ó�� ���� ��尡 q�� �� �� ���� ��찡 �����.
			if (edge[x][i] == 1 && check[i] == true) {
				check[i] = false;
				q.push(i);
			}
		}
	}
}

int main(void) {
	int V = 0;
	int es = 0, ee = 0; //edge start , edge end
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 1; i < M + 1; i++) {
		node[i] = i; //��� ��ȣ �ο�
		scanf("%d %d", &es, &ee);
		edge[es][ee] = 1; //���� ����
		edge[ee][es] = 1; //����� ���� ����
	}
	dfs(V);
	printf("\n");
	bfs(V);

	return 0;
}