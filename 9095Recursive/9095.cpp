/*
2019-03-23
��ȯ��


����
���� 4�� 1, 2, 3�� ������ ��Ÿ���� ����� �� 7������ �ִ�. ���� ��Ÿ�� ���� ���� 1�� �̻� ����ؾ� �Ѵ�.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
���� n�� �־����� ��, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���� n�� �־�����. n�� ����̸� 11���� �۴�.

���
�� �׽�Ʈ ���̽�����, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ����Ѵ�.


*/

#include <iostream>
using namespace std;

int recursive(int sum, int goal) {
	
	int num = 0;
	if (sum > goal) {
		//������ ã�� �� ���� ���
		return 0;
	}
	else if (sum == goal) {
		//������ ���
		return 1;
	}
	else {
		//�ٽ� ȣ���ؾ��ϴ� ���
		for (int i = 1; i < 4; i++) {
			num += recursive(sum + i, goal);
		}
	}
	return num;
}

int main(void) {
	int t = 0;
	cin >> t;
	
	while (t--) {
		int count = 0, sum = 0, goal=0;
		cin >> goal;
		cout << recursive(sum, goal) << "\n";
	}

	return 0;
}