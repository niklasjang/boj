/*
2019-00-00
��ȯ��

����
N���� ������ �̷���� ������ ���� ��, ���̰� ����� �κм��� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ������ ��Ÿ���� N�� ���� S�� �־�����. (1 �� N �� 20, |S| �� 1,000,000) ��° �ٿ� N���� ������ �� ĭ�� ���̿� �ΰ� �־�����. �־����� ������ ������ 100,000�� ���� �ʴ´�.

���
ù° �ٿ� ���� S�� �Ǵ� �κм����� ������ ����Ѵ�.

*/


#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;
int set[MAX];
int N, S;


int go(int depth, int sum) {
	if (depth == N) {
		//���������� OXXXXX���� OOOXXX���� Ȯ���ϸ� �ȴ�. ex) 2XXXXX / 2 -2 2 XXX �� �� ���� 2
		if (sum == S) {
			return 1;
		}
		else {
			return 0;
		}
	}
	//�ٽ� call �ؾ��ϴ� ���
	int count = 0;
	count += go(depth + 1, sum + set[depth]);
	count += go(depth + 1, sum);
	return count;
}

int main(void) {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> set[i];
	}
	if (S == 0) {
		cout << go(0, 0) -1 << "\n";

	}
	else {
		cout << go(0, 0) << "\n";

	}

	return 0;
}