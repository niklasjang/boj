/*
2019-04-05
��ȯ��

N���� �ڿ����� �ڿ��� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. N���� �ڿ����� ��� �ٸ� ���̴�.

N���� �ڿ��� �߿��� M���� �� ����
�Է�
ù° �ٿ� N�� M�� �־�����. (1 �� M �� N �� 8)

��° �ٿ� N���� ���� �־�����. �Է����� �־����� ���� 10,000���� �۰ų� ���� �ڿ����̴�.

���
�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ������ ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.

������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int N = 0, M = 0, index;
int arr[9];
int num[9];
bool color[9];

void go(int index) {
	if (index == M) {
		for (int i = 0; i < M;i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
	}
	else {
		for (int value = 0; value < N; value++) {
			if (color[value] == true) continue;
			if (value != 0 && color[value - 1] == false && arr[value - 1] == arr[value]) continue;
			if (index != 0 && num[index - 1] > arr[value]) continue;
			color[value] = true;
			num[index] = arr[value];
			go(index + 1);
			color[value] = false;
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M); //���ؿ����� scanf_s�� �������  ���ϳ�?
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, &arr[N]);
	go(0);
	return 0;
}