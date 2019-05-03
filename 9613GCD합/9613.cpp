/*
2019-03-14
niklasjang ��ȯ��


����
���� ���� n���� �־����� ��, ������ ��� ���� GCD�� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (1 �� t �� 100)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. �� �׽�Ʈ ���̽��� ���� ���� n (1 < n �� 100)�� �־�����, �������� n���� ���� �־�����. �Է����� �־����� ���� 1000000�� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽����� ������ ��� ���� GCD�� ���� ����Ѵ�.


*/

#include <iostream>
#include <list>
using std::cout;
using std::cin;
using std::endl;
using std::list;

int gcd(int a, int b) {
	//recursive ����
	if (b == 0)
		return a;
	else
		gcd(b, b%a);
}

int main(void) {
	int testCase, num;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		list<int> lst;
		list<int>::iterator it;
		int length;
		cin >> length;
		for (int j = 0; j < length; j++) {
			cin >> num;
			lst.push_back(num);
		}
		for (it = lst.begin(); it != lst.end(); it++)
			cout << *it << endl;
	}
	return 0;
}