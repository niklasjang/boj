/*
2019-04-09
장환석

문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.

	
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, u, v, ans=0;
vector<int> a[1001];
bool check[1001];

void dfs(int x) { 
	check[x] = true;
	
	for (int i = 0; i <a[x].size(); i++) {
		if (check[a[x][i]] == false) {
			dfs(a[x][i]);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	check[x] = true;
	q.push(x);
	while (!q.empty()) {
		int y = q.front(); q.pop();
		for (int i = 0; i < a[y].size(); i++) {
			if (check[a[y][i]] == false) {
				check[a[y][i]] = true;
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

	//정렬
	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	//모든 점에 대해서 한번씩 확인하면서 connected components를 찾는다
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			ans += 1;
			bfs(i);
		}
	}
	printf("%d ", ans);
	return 0;
}