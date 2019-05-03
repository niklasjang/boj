/*
2019-03-13
niklasjang ��ȯ��
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int gcd(int a, int b) {
	//recursive ����
	if (b == 0)
		return a;
	else
		gcd(b, b%a);
}

int gcd2(int a, int b) {
	//while ����
	while (!(b == 0)) {
		int r = b % a;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << gcd2(a, b) << endl;
	return 0;
}