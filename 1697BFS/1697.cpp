/*
2019-05-08
��ȯ��

���ٲ���
�ð� ����	�޸� ����	����	����	���� ���	���� ����
2 ��	128 MB	52572	14518	8972	24.719%
����
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�. �����̴� �Ȱų� �����̵��� �� �� �ִ�. ����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. �����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.

�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.

���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.

*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int N, K;
int check[200000]; //0�� �湮���� ����. ������ 1 ���� step�� 2 ~~~ �� step ������ �ִ밪 -1
int bfs(int start) {
	queue<int> q;
	check[start] = 1;
	q.push(start);
	int temp = 0;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		temp = curr * 2;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				check[temp] = check[curr] + 1;
				q.push(temp);
			}
		}
		temp = curr + 1;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				check[temp] = check[curr] + 1;
				q.push(temp);
			}
		}
		temp = curr - 1;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				check[temp] = check[curr] + 1;
				q.push(temp);
			}
		}
	}
	return -1;
}

int main(void) {
	scanf("%d %d", &N, &K);
	bfs(N);
	printf("%d\n",check[K]-1);
	return 0;
}