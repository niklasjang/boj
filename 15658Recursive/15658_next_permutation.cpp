/*
2019-03-22
��ȯ��

����
N���� ���� �̷���� ���� A1, A2, ..., AN�� �־�����. ��, ���� �� ���̿� �������� �� �ִ� N-1���� �����ڰ� �־�����. �����ڴ� ����(+), ����(-), ����(��), ������(��)���θ� �̷���� �ִ�.

�츮�� ���� �� ���̿� �����ڸ� �ϳ��� �־, ������ �ϳ� ���� �� �ִ�. �̶�, �־��� ���� ������ �ٲٸ� �ȵȴ�.

���� ���, 6���� ���� �̷���� ������ 1, 2, 3, 4, 5, 6�̰�, �־��� �����ڰ� ����(+) 2��, ����(-) 1��, ����(��) 1��, ������(��) 1���� ��쿡�� �� 60������ ���� ���� �� �ִ�. ���� ���, �Ʒ��� ���� ���� ���� �� �ִ�.

1+2+3-4��5��6
1��2+3+4-5��6
1+2��3��4-5+6
1��2��3-4+5+6
���� ����� ������ �켱 ������ �����ϰ� �տ������� �����ؾ� �Ѵ�. ��, �������� ���� ���������� �� ���Ѵ�. ������ ����� ���� ���� C++14�� ������ ������. ��, ����� �ٲ� �� ���� ���ϰ�, �� ���� ������ �ٲ� �Ͱ� ����. �̿� ����, ���� �� 4���� ����� ����غ��� �Ʒ��� ����.

1+2+3-4��5��6 = 1
1��2+3+4-5��6 = 12
1+2��3��4-5+6 = 5
1��2��3-4+5+6 = 7
N���� ���� N-1���� �����ڰ� �־����� ��, ���� �� �ִ� ���� ����� �ִ��� �Ͱ� �ּ��� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(2 �� N �� 11)�� �־�����. ��° �ٿ��� A1, A2, ..., AN�� �־�����. (1 �� Ai �� 100) ��° �ٿ��� ���� N-1�� 4���� ������ �־����µ�, ���ʴ�� ����(+)�� ����, ����(-)�� ����, ����(��)�� ����, ������(��)�� �����̴�.

���
ù° �ٿ� ���� �� �ִ� ���� ����� �ִ���, ��° �ٿ��� �ּڰ��� ����Ѵ�. �ִ񰪰� �ּڰ��� �׻� -10�ﺸ�� ũ�ų� ����, 10�ﺸ�� �۰ų� ���� ����� ������ �Է¸� �־�����. ����, �տ������� ������� ��, �߰��� ���Ǵ� ���� ����� �׻� -10�ﺸ�� ũ�ų� ����, 10�ﺸ�� �۰ų� ����.
*/

#include <iostream>

inline int bigger(int a, int b) { return a > b ? a : b; }
inline int smaller(int a, int b) { return a < b ? a : b; }

using namespace std;
const int MAX = 45;
int a[MAX];
int N;
int ans_max = -1000000001;
int ans_min = +1000000001;
int opt1, opt2, opt3, opt4;

int go(int result, int index, int pls, int min, int mul, int divide) {
	if (index == N - 1) {
		ans_max = bigger(result, ans_max);
		ans_min = smaller(result, ans_min);
		return 0;
	}
	else { //index < N
		if (pls > 0) {
			go(result + a[index + 1], index + 1, pls - 1, min, mul, divide);
		}
		if (min > 0) {
			go(result - a[index + 1], index + 1, pls, min - 1, mul, divide);
		}
		if (mul > 0) {
			go(result * a[index + 1], index + 1, pls, min, mul - 1, divide);
		}
		if (divide > 0) {
			go(result / a[index + 1], index + 1, pls, min, mul, divide - 1);
		}
		return 0;
	}
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	cin >> opt1 >> opt2 >> opt3 >> opt4;
	go(a[0], 0, opt1, opt2, opt3, opt4);
	cout << ans_max << "\n";
	cout << ans_min << "\n";
	return 0;
}