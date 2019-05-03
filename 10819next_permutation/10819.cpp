/*
2019-03-21
��ȯ��
����
N���� ������ �̷���� �迭 A�� �־�����. �̶�, �迭�� ����ִ� ������ ������ ������ �ٲ㼭 ���� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

�Է�
ù° �ٿ� N (3 �� N �� 8)�� �־�����. ��° �ٿ��� �迭 A�� ����ִ� ������ �־�����. �迭�� ����ִ� ������ -100���� ũ�ų� ����, 100���� �۰ų� ����.

���
ù° �ٿ� �迭�� ����ִ� ���� ������ ������ �ٲ㼭 ���� �� �ִ� ���� �ִ��� ����Ѵ�.
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 8;
int arr[MAX];
int N;

int GetAbsolute(int x, int y) {
	if (x >= y) {
		//cout << x << "-" << y << endl;
		return x - y;
	}
	else {
		//cout << y << "-" << x << endl;
		return y - x;
	}
}

int main(void) {
	int ans = 0, abs = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, &arr[N]);
	do {
		abs = 0;
		for (int i = 0; i < N-1; i++) {
			abs += GetAbsolute(arr[i], arr[i+1]);
		}
		//cout << "abs is..." << abs<<endl;
		if (abs > ans) {
			ans = abs;
		}
		
	} while (next_permutation(arr, &arr[N]));
	cout << ans << "\n";	
	return 0;
}