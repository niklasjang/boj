/*
2019-03-21
��ȯ��

����
N�� �־����� ��, 1���� N������ ���� �̷���� ������ ���������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1 �� N �� 8)�� �־�����.

���
ù° �ٺ��� N!���� �ٿ� ���ļ� ��� ������ ���������� ����Ѵ�.
*/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[8];
int N;
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		arr[i] = i+1;
	}

	do{
		for (int i = 0; i < N; i++ ) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(arr, &arr[N]));
	return 0;
}