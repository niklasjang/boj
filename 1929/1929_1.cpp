/*
20109-03-15
��ȯ��


����
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1 �� M �� N �� 1,000,000)

���
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.


Ǯ�� :
��� ���ڿ� ���ؼ� prime���� Ȯ���ϴ� �˰����� �����Ѵ�.
40��° ���� cout << i << "\n";�� cout<< i <<endl;�� ��ġ�� �ð� �ʰ��� Ż���Ѵ�.
*/
#include <iostream>
using namespace std;

bool prime(int num) {
	if (num < 2) {
		return false;
	}
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (prime(i))
			::cout << i << "\n";
	return 0;
}