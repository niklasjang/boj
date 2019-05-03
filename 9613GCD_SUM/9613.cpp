/*
2019-03-14
niklasjang ��ȯ��


����
���� ���� n���� �־����� ��, ������ ��� ���� GCD�� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (1 �� t �� 100)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. �� �׽�Ʈ ���̽��� ���� ���� n (1 < n �� 100)�� �־�����, �������� n���� ���� �־�����. �Է����� �־����� ���� 1000000�� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽����� ������ ��� ���� GCD�� ���� ����Ѵ�.



��°��� type�� int���̸� Ʋ���� long long���̸� �´ٰ� ä���� �ȴ�!!


*/
#include <iostream>
using namespace std;
int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}
int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int arr[111];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << endl;
	}
	return 0;
}