/*
2019-03-14
niklasjang ��ȯ��


����
���� ���� n���� �־����� ��, ������ ��� ���� GCD�� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (1 �� t �� 100)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. 
�� �׽�Ʈ ���̽��� ���� ���� n (1 < n �� 100)�� �־�����, �������� n���� ���� �־�����. �Է����� �־����� ���� 1000000�� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽����� ������ ��� ���� GCD�� ���� ����Ѵ�.


���� 9613.cpp ������ ���� �ٽ� �ۼ��غ� ����

��°��� type�� int���̸� Ʋ���� long long���̸� �´ٰ� ä���� �ȴ�!!

*/

#include <iostream>
using namespace std;

int gcd(int x, int y) {
	/*
	GCD �Լ� : ��Ŭ���� ȣ����
	���� : GCD(a,b) = GCD(b,a%b)�̰�, GCD(x,y)���� y�� 0�� �� x�� y�� GCD�� x�̴�.
	*/
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main(void) {
	/*
	������ �ſ� �����ϰ� Ǯ���մϴ�. pair<int,int>�� list<<pair<int,int>> type�� ����ϸ� �������� ���Դϴ�. ������ ������ �迭�� ����ؼ� Ǯ���ϴ� ���� �����ϴ�.
	*/
	int testCase, n;
	long long result = 0;
	int arr[111];

	cin >> testCase;
	while (testCase--) {
		cin >> n;
		for (int i = 0; i < n;i++) {
			cin >> arr[i];
		}
		result = 0; // //���⿡�� long long�� ����մϴ�. int���� ����ϸ� ǥ�� ���� ������ �Ѿ �� �ֽ��ϴ�. 
		for (int j = 0; j < n - 1; j++) {
			for (int k = j+1; k < n; k++) {
				result += gcd(arr[j], arr[k]);
			}
		}
		cout << result << endl;
	}
	return 0;
}