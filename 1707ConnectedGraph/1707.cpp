/*
2019-05-04
��ȯ��

����
�׷����� ������ ������ �ѷ� �����Ͽ�, �� ���տ� ���� ���������� ���� �������� �ʵ��� ������ �� ���� ��, �׷��� �׷����� Ư���� �̺� �׷��� (Bipartite Graph) �� �θ���.

�׷����� �Է����� �־����� ��, �� �׷����� �̺� �׷������� �ƴ��� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �����Ǿ� �ִµ�, ù° �ٿ� �׽�Ʈ ���̽��� ���� K(2��K��5)�� �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ��� �׷����� ������ ���� V(1��V��20,000)�� ������ ���� E(1��E��200,000)�� �� ĭ�� ���̿� �ΰ� ������� �־�����. �� �������� 1���� V���� ���ʷ� ��ȣ�� �پ� �ִ�. �̾ ��° �ٺ��� E���� �ٿ� ���� ������ ���� ������ �־����µ�, �� �ٿ� ������ �� ������ ��ȣ�� �� ĭ�� ���̿� �ΰ� �־�����.

���
K���� �ٿ� ���� �Է����� �־��� �׷����� �̺� �׷����̸� YES, �ƴϸ� NO�� ������� ����Ѵ�.

*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> a[20001];
int color[20001]; //0 :defulat, 1, Group A, 2: Group 2

void dfs(int node, int c) {
	color[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (color[next] == 0) {
			dfs(next, 3 - c);
		}
	}
}



int main(void) {
	int K, V, E, u, v;
	scanf("%d ", &K);
	while (K--) {
		
		scanf("%d %d", &V, &E);

		for (int i = 1; i <= V; i++) {
			a[i].clear();
			color[i] = 0;
		}
		
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}

		//��ĥ�Ѵ�.
		for (int i = 1; i <= V; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}

		//�˻��Ѵ�.
		bool OK = true;
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int y = a[i][j];
				if (color[i] == color[y]) {
					OK = false;
				}
			}
		}

		printf("%s\n", OK ? "YES" : "NO");
	}
	return 0;
}