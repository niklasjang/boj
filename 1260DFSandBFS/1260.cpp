/*
2019-04-07
장환석

문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

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
	check[x] = true; //방문했는지 안했는지는 노드기준으로. 에지 기준 아님
	printf("%d ", x);
	for (int i = 1; i < N+1; i++) {//모든 노드에 대해서
		if (edge[x][i] == 1 && check[i]==false) {//현재 노드에서 다른 노드로 가는 길이 있고, 그 길을 안갔으면
			dfs(i);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	check[x] = true; q.push(x);
	while (!q.empty()) {
		int x = q.front(); q.pop(); //q의 front를 빼서 그 값을 탐색.
		printf("%d ", x);
		for (int i = 1; i < N+1; i++) {//이번 x와 인접한 모든 노드를 다 q에 넣는다.
			//해당 노드를 방문할 때 q에 넣으면 강의에서 설명한 것처럼 같은 노드가 q에 두 번 들어가는 경우가 생긴다.
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
		node[i] = i; //노드 번호 부여
		scanf_s("%d %d", &es, &ee);
		edge[es][ee] = 1; //에지 저장
		edge[ee][es] = 1; //양방향 에지 저장
	}
	dfs(start_node);
	printf("\n");
	memset(check, false, 1000 + 1);
	bfs(start_node);

	return 0;
}