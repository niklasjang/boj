#include <iostream>
#include <queue>
using namespace std;
int N, M;
int node[1000 + 1];
bool check[1000 + 1];
int edge[1000 + 1][1000 + 1];

void dfs(int x) {
	check[x] = true; //방문했는지 안했는지는 노드기준으로. 에지 기준 아님
	printf("%d ", x);
	for (int i = 1; i < N + 1; i++) {//모든 노드에 대해서
		if (edge[x][i] == 1 && check[i] == false) {//현재 노드에서 다른 노드로 가는 길이 있고, 그 길을 안갔으면
			dfs(i);
		}
	}
}

void bfs(int x) { //여기선 false가 방문한 상태
	queue<int> q;
	check[x] = false;
	q.push(x);
	while (!q.empty()) {
		x = q.front(); q.pop(); //q의 front를 빼서 그 값을 탐색.
		printf("%d ", x);
		for (int i = 1; i < N + 1; i++) {//이번 x와 인접한 모든 노드를 다 q에 넣는다.
			//해당 노드를 방문할 때 q에 넣으면 강의에서 설명한 것처럼 같은 노드가 q에 두 번 들어가는 경우가 생긴다.
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
		node[i] = i; //노드 번호 부여
		scanf("%d %d", &es, &ee);
		edge[es][ee] = 1; //에지 저장
		edge[ee][es] = 1; //양방향 에지 저장
	}
	dfs(V);
	printf("\n");
	bfs(V);

	return 0;
}