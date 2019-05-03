#include <iostream>
#include <list>
int main()
{
	std::list<int> A;
	std::list<int>::iterator it;
	A.push_back(1); A.push_back(2); A.push_back(3);
	for (it = A.begin(); it != A.end(); it++)
		std::cout << *it << std::endl;
	it = A.end(); it--;
	while (it != A.begin()) {
		std::cout << *it << std::endl;
		it--;
	}
	std::cout << *it << std::endl;
	return 0;
}
�ڿ���  a,b,c�� ���ؼ� ax +by = c �� ���� c�� GCD(a,b)�� ����� ���� �����ظ� ���´�. 
���� �Ҽ� P�� P�� ����� �ƴ� �ڿ��� a�� ���ؼ�  ax+py =GCD(a,p)�� �����ظ� ���� ���� �ڸ��ϴ�. 
a�� p�� ���μ� �����̹Ƿ� ax+py = 1�� ���� �� �ִ�.
Ȯ�� ��Ŭ���� �˰����� GCD(a,b) = GCD(b,a%b)�� ���� �� ������ �ǹ��Ѵ�.
a�� b�� �������� �� a = bq+r�̶�� �Ѵٸ� (bq+r)x + by = 1 = b(qx+y) + rx�̱� �����̴�. 
�������� GCD(a,b)�� GCD(b, a%b)�� ���� b�� 1�̰ų� a%b�� ����� 0�� �� ���� �� �ִ�. �� ������ �����ϴ� ���� ������ ���� ã�� �� �ִ�

ex1. GCD(11,5) = GCD(5, 11%5)
11%5 = 1 -> 11 - 5*2 = 1 -> 11*1 + 5*(-2) = 1 -> �����̹Ƿ� �纯 5*11���ؼ� ���� 9
ex2. GCD(7,4) = GCD(4 ,7-4) = GCD(7-4, 4 % 4-(7-4)) -> 4-(7-4) = -7 + 4*2 = 1 ���� ���� 2.
