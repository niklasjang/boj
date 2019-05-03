/*
2019-03-14
niklasjang
��ȯ��

����:
�� �ڿ��� A�� B�� ���ؼ�, A�� ����̸鼭 B�� ����� �ڿ����� A�� B�� �������� �Ѵ�. �̷� ����� �߿��� ���� ���� ���� �ּҰ������� �Ѵ�. ���� ���, 6�� 15�� ������� 30, 60, 90���� ������, �ּ� ������� 30�̴�.

�� �ڿ��� A�� B�� �־����� ��, A�� B�� �ּҰ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�:
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. ��° �ٺ��� T���� �ٿ� ���ļ� A�� B�� �־�����. (1 �� A, B �� 45,000)

���
ù° �ٺ��� T���� �ٿ� A�� B�� �ּҰ������ �Է¹��� ������� �� �ٿ� �ϳ��� ����Ѵ�.

*/

#include <iostream>
using namespace std;

int GCD(int a, int b) {
	//cout << "GCD callde (" << a << "," << b << ")" << endl;

	if (b == 0)
		return a;
	else {
		return GCD(b, a%b);
	}
}

int LCD(int a, int b) {
	//cout << "LCD callde (" << a << "," << b << ")" << endl;
	int gcd = GCD(a, b);
	return a * b / gcd;
}

int main(void) {
	int index;
	cin >> index;
	for (int i = 0; i < index; i++) {
		//cout << "for callde" << endl;
		pair<int, int> ab;
		cin >> ab.first >> ab.second;
		cout << LCD(ab.first, ab.second) << endl;
	}
}