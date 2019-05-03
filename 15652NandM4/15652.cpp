/*
2019-04-05
��ȯ��

�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� M���� �� ����
���� ���� ���� �� ��� �ȴ�.
�� ������ �񳻸������̾�� �Ѵ�.
���̰� K�� ���� A�� A1 �� A2 �� ... �� AK-1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.

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
			if (index == 0){
				arr[0] = value;
				go(arr, index + 1);
			}
			else {
				if (arr[index - 1] <= value) {
					arr[index] = value;
					go(arr, index + 1);
				}
			}
		}
	}
}

int main(void) {
	int arr[9] = { 0, 0,0,0,0,0,0,0,0};
	scanf_s("%d %d", &N, &M); //���ؿ����� scanf_s�� �������  ���ϳ�?
	go(arr, 0);
	return 0;
}