/*
2019-04-09
��ȯ��

����
���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. (1 �� N �� 1,000, 0 �� M �� N��(N-1)/2) ��° �ٺ��� M���� �ٿ� ������ �� ���� u�� v�� �־�����. (1 �� u, v �� N, u �� v) ���� ������ �� ���� �־�����.

���
ù° �ٿ� ���� ����� ������ ����Ѵ�.

	
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, u, v, ans=0;
vector<int> a[1001];
bool color[1001];

void dfs(int x) { 
	color[x] = true;
	
	for (int i = 0; i <a[x].size(); i++) {
		if (color[a[x][i]] == false) {
			dfs(a[x][i]);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	color[x] = true;
	q.push(x);
	while (!q.empty()) {
		int y = q.front(); q.pop();
		for (int i = 0; i < a[y].size(); i++) {
			if (color[a[y][i]] == false) {
				color[a[y][i]] = true;
				q.push(a[y][i]);
			}
		}
	}

}



int main(void) {
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	//����
	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	//��� ���� ���ؼ� �ѹ��� Ȯ���ϸ鼭 connected components�� ã�´�
	for (int i = 1; i <= N; i++) {
		if (color[i] == false) {
			ans += 1;
			bfs(i);
		}
	}
	printf("%d ", ans);
	return 0;
}