/*
2019-04-01
��ȯ��

����
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
�Է�
ù° �ٿ� �ڿ��� N�� M�� �־�����. (1 �� M �� N �� 8)

���
�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ������ ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.

������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.


*/

#include <iostream>
#include <cstdio>
using namespace std;
int N = 0, M = 0, index;

int go(int arr[], int index) {
	if (index == M) {
		for (int i = 0; i < M;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return 0;
	}
	else {
		for (int value = 1; value <= N; value++) {
			arr[index] = value;
			go(arr, index+1);			
		}
	}
}

int main(void) {
	int arr[9] = { 0, };
	scanf("%d %d", &N, &M); //���ؿ����� scanf_s�� �������  ���ϳ�?
	go(arr, 0);
	return 0;
}