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

 boolean param�� fatorial �Լ��� �� �� ���� ����ǵ��� �ϴ� ������ �Ѵ�.


 �޸� �ʰ��� Ʋ�ȴٰ� ���� �ФФФФФФФФФФФФФФФФФФФФ� �� boolean�� �������ϳ�? stack frame ���̰� ��û �þ�ݾ�!
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int boolean = true;
int factMoulder(int a, int b) {
	//factorial with moduler
	//cout << "factorial (" << a << "," << b << ")" << endl;
	if (a == 0 )
		return 1;
	else {
		//cout << "a is.." << a << endl;
		//cout << "fact result is..." << result << endl;
		return (a % b * factMoulder(a - 1, b)) % b;
	}
}

int gcd(int a, int b, bool boolean) {
	//cout << "gcd (" << a << "," << b << ")" << endl;
	if (b == 0) //GCD(a!,b)���� b�� 0�̸� a �� GCD
		return a;
	else {//GCD(b, a!%b)�� �Ǵ�
		if (boolean == true) {
			int c = factMoulder(a, b);
			if (c == 0) //GCD(b, a!%b)���� a!%b�� 0�� ���
				return b; 
			return gcd(c, b%c, false);
		}
		return gcd(b, a%b, false);
	}
}

int main(void){
	int a, b;
	cin >> a >> b;
	cout<< gcd(a, b, true) << endl;;
	return 0;
}
