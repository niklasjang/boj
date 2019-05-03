/*
2019-04-07
��ȯ��

����
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����. ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. � �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. �Է����� �־����� ������ ������̴�.

���
ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int node[1000 + 1];
bool check[1000 + 1];
int edge[1000 + 1][1000+1];

void dfs(int x) {
	check[x] = true; //�湮�ߴ��� ���ߴ����� ����������. ���� ���� �ƴ�
	printf("%d ", x);
	for (int i = 1; i < N+1; i++) {//��� ��忡 ���ؼ�
		if (edge[x][i] == 1 && check[i]==false) {//���� ��忡�� �ٸ� ���� ���� ���� �ְ�, �� ���� �Ȱ�����
			dfs(i);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	check[x] = true; q.push(x);
	while (!q.empty()) {
		int x = q.front(); q.pop(); //q�� front�� ���� �� ���� Ž��.
		printf("%d ", x);
		for (int i = 1; i < N+1; i++) {//�̹� x�� ������ ��� ��带 �� q�� �ִ´�.
			//�ش� ��带 �湮�� �� q�� ������ ���ǿ��� ������ ��ó�� ���� ��尡 q�� �� �� ���� ��찡 �����.
			if (edge[x][i] == 1 && check[i] == false) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

int main(void) {
	int start_node=0;
	int es=0, ee=0; //edge start , edge end
	scanf_s("%d %d %d", &N, &M, &start_node);

	for (int i = 1; i < N+1; i++) {
		node[i] = i; //��� ��ȣ �ο�
		scanf_s("%d %d", &es, &ee);
		edge[es][ee] = 1; //���� ����
		edge[ee][es] = 1; //����� ���� ����
	}
	dfs(start_node);
	printf("\n");
	memset(check, false, 1000 + 1);
	bfs(start_node);

	return 0;
}