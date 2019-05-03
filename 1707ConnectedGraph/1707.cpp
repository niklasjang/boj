/*
2019-00-00
장환석

문제
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K(2≤K≤5)가 주어진다. 각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V(1≤V≤20,000)와 간선의 개수 E(1≤E≤200,000)가 빈 칸을 사이에 두고 순서대로 주어진다. 각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 각 줄에 인접한 두 정점의 번호가 빈 칸을 사이에 두고 주어진다.

출력
K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.

*/

#include <iostream>
#include <vector>
using namespace std;

int K, N, M;
vector<int> a[20001];
int check[20001]; //default = 0, group A = 1, group B = 2

void dfs(int x) {
	if (check[x] == 0) {
		check[x] = 1;
	}
	for (int i = 0;i < a[x].size(); i++) {
		if (check[a[x][i]] == 0) {
			if (check[x] == 1) {
				check[a[x][i]] = 2
			}
			else if {
				check[a[x][i]] = 1
			}
		}
	}
}

int main(void) {
	scanf_s("%d", &K);
	while (K--) {
		scanf_s("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			int es, ed;
			scanf_s("%d %d", &es, &ed);
			a[es].push_back(ed);
			a[ed].push_back(es);
		}
		dfs(1);
		bfs(1);
	}

	return 0;
}