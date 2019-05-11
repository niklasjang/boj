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
#include <stack>

using namespace std;
int N, K;
int check[200000]; //0�� �湮���� ����. ������ 1 ���� step�� 2 ~~~ �� step ������ �ִ밪 -1
void bfs(int start) {
	queue<pair<int, int> > q;
	queue<pair<int, int> > next_q;
	stack<pair<int, int> > stck;
	stack<int > output;
	q.push(make_pair(start,-1));  check[start] = 1; //���� �� check
	int temp = 0;
	int second = 0;
	while (!q.empty()) {
		int curr = 0, prv = 0;
		curr = q.front().first;
		prv = q.front().second;
		q.pop(); //�� �� stack�� �־�α�
		stck.push(make_pair(curr, prv));
		temp = curr * 2;	
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				next_q.push(make_pair(temp, curr));
				check[temp] = check[curr] +1;
			}
		}
		temp = curr + 1;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				next_q.push(make_pair(temp, curr));
				check[temp] = check[curr] + 1;
			}
		}
		temp = curr - 1;
		if (0 <= temp && temp < 200000) {
			if (check[temp] == 0) {
				next_q.push(make_pair(temp, curr));
				check[temp] = check[curr] + 1;
			}
		}

		if (q.empty()) {
			//������ ť�� ��� ���� �� check�� Ȯ���ϰ�
			//���� t���� queue�� �����鼭 check�� ������
			if (check[K] == check[curr]) {
				printf("%d\n", second);
				break;
			}
			second += 1;
			q = next_q;
			next_q = queue<pair<int, int> >();
		}
	}
	int aim = K;
	while (!stck.empty()) {
		pair<int, int> curr = stck.top();
		stck.pop();
		if (curr.first == aim) {
			output.push(curr.first);
			aim = curr.second; //aim = prv;
		}
	}

	while (!output.empty()) {
		printf("%d ", output.top());
		output.pop();
	}
}

int main(void) {
	scanf("%d %d", &N, &K);
	bfs(N);
	return 0;
}