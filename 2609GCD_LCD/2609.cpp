/*
2019-03-14
niklasjang
��ȯ��

����:
�� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�:
ù° �ٿ��� �� ���� �ڿ����� �־�����. �� ���� 10,000������ �ڿ����̸� ���̿� �� ĭ�� ������ �־�����.

���
ù° �ٿ��� �Է����� �־��� �� ���� �ִ�������,��° �ٿ��� �Է����� �־��� �� ���� �ּ� ������� ����Ѵ�.

*/

#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;
	else {
		return GCD(b, a%b);
	}
}

int LCD(int a, int b, int gcd) {
	cout << gcd << endl;
	return a * b / gcd;
}

int main(void) {
	int a, b, gcd;
	cin >> a >> b;
	gcd = GCD(a, b);
	cout << LCD(a, b, gcd) << endl;
}