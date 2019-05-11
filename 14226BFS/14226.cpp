#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int S;
int check[1002][1002]; //[�ش� step���� ȭ�鿡 �ִ� �̸�Ƽ�� ��][Ŭ�����忡 �ִ� �̸�Ƽ�� ��]

int bfs(int start) {
	queue<pair<int, int>> q;
	check[start][0] = 1;
	q.push(make_pair(start, 0));
	while (!q.empty()) {
		pair<int, int> curr = q.front(); q.pop();

		//Ŭ������ ����
		if (check[curr.first][curr.first] == 0 && curr.first != curr.second) {
			check[curr.first][curr.first] = check[curr.first][curr.second] + 1;
			if (curr.first == S) return curr.second;
			q.push(make_pair(curr.first, curr.first));
		}
		//�����ֱ�
		if (curr.first + curr.second <= S && check[curr.first + curr.second][curr.second] == 0 ) {
			check[curr.first + curr.second][curr.second] = check[curr.first][curr.second] + 1;
			if (curr.first + curr.second == S) return curr.second;
			q.push(make_pair(curr.first + curr.second, curr.second));
		}
		//�ϳ� ����
		if (check[curr.first - 1][curr.second] == 0 && curr.first - 1 >= 0) {
			check[curr.first - 1][curr.second] = check[curr.first][curr.second] + 1;
			if (curr.first - 1 == S) return curr.second;
			q.push(make_pair(curr.first - 1, curr.second));
		}
	}
	return -1;
}

int main(void) {
	scanf_s("%d", &S);
	int clip = 0;
	clip = bfs(1);
	printf("%d\n", check[S][clip] - 1);
	return 0;
}