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
void bfs(int start) {
	queue<int> q;
	queue<int> next_q;
	q.push(start);
	int temp = 0;
	int second = 0;
	while (!q.empty()) {
		int curr = q.front(); 
		q.pop(); check[curr] += 1; //���ٲ��� 2���������� pop�� �� �� count�� ���ش�.
		temp = curr * 2;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				next_q.push(temp);
			}
		}
		temp = curr + 1;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				next_q.push(temp);
			}
		}
		temp = curr - 1;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				next_q.push(temp);
			}
		}

		if (q.empty()) {
			if (check[K] != 0) {
				printf("%d\n", second);
				printf("%d\n", check[K]);
				break;
			}
			second += 1;
			q = next_q;
			next_q = queue<int>();
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &K);
	bfs(N);
	return 0;
}