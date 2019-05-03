/*
2019-03-13
niklasjang ��ȯ��

�� ���� �ִ������� �� ���� ������ ���� ���� �� �ִ� ���� ū �ڿ����� �����Ѵ�. ���� ���, 8�� 12�� �ִ������� GCD(8,12)�� ��Ÿ����, �� ���� 4�̴�. 4�� 8�� 12�� ���� �� �ִ� ���� ū �����̱� �����̴�. (8�� 12�� ������� 1, 2, 4�� �ִ�)

�ڿ����� ���丮���� �� ������ �۰ų� ���� ��� ���� ������ ���̴�. ���� ���, 5�� ���丮���� 5!�� ��Ÿ���� 1*2*3*4*5 = 120�̴�. (0!�� 1�� ���Ѵ�)

�� �� n�� k�� �־����� ��, n!�� k�� �ִ������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, n = 3, k = 10�̶��, GCD(n!,k) = GCD(3!,10) = GCD(1*2*3,10) = GCD(6,10) = 2�� �ȴ�.

�Է� : �� �ٿ� n�� k�� �ϳ��� �־�����. (0 �� n �� 1,000,000,000, 1 �� k �� 1,000,000,000)

��� : �Է��� �� �ٿ� ���ؼ�, n!�� k�� �ִ������� ����Ѵ�.

Ǯ�� :
10430�� moduler���� ��� �Ʒ� ���� ����ؼ�,
n! % k =( (n%k) * (n-1!%k) ) % k
 ��û ū ���� factorial�� ���� ������ GCD�� ���ϴ� ���� �ƴ϶� factorial�� ���ϴ� �������� moduler�� ����ؼ�
 ū ���� ������ �ʿ���� GCD�� ���Ѵ�.

 �޸� �ʰ��� Ʋ�ȴٰ� ���� �ФФФФФФФФФФФФФФФФФФФФ�

 boolean ������ ����ϰ� ��������� recursion�� ���� �ȵǴ� ��.
 ��, for���� ����ؼ� Ǯ���
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int factMoulder(int a, int b) {
	//factorial with moduler
	//cout << "factorial (" << a << "," << b << ")" << endl;
	if (a == 0)
		return 1;
	else {
		//cout << "a is.." << a << endl;
		//cout << "fact result is..." << result << endl;
		return (a % b * factMoulder(a - 1, b)) % b;
	}
}

int gcd(int a, int b) {
	//cout << "gcd (" << a << "," << b << ")" << endl;
	if (b == 0) //GCD(a!,b)���� b�� 0�̸� a �� GCD
		return a;
	else {
		return gcd(b, a%b);
	}
}

int main(void) {
	int a, b;
	cin >> a >> b;
	a = factMoulder(a, b);
	cout << gcd(b, a) << endl;;
	return 0;
}
