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
int arr[9];
bool color[9];

void go(int index) {
	if (index == M) {
		for (int i = 0; i < M;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else {
		for (int value = 1; value <= N; value++) {
			if (color[value] == true) continue; //�ش� ���ڸ� ����߾����� continue
			color[value] = true; //��� �������� ����� ���̶� true�� �ٲٰ�
			arr[index] = value; //arr[index++]�� ó������ �ߺ��� ���� ������ ���� �͵��� �������ش�.
			go(index + 1); //arr�ȿ� index��°���� ������� ���� call�� �Ѵ�.
			color[value] = false; //call�� ������ #37��° �ٿ��� ����ߴ� ���� ���� for�������� ������� ���� ������ �����ؾ��ϱ�� ������(++�� value ������ arr[index]�� �� �� �ִ��� Ȯ���ϱ� ����)
			//check[value] = false�� �Ѵ�.
		}
	}
}

int main(void) {
	scanf_s("%d %d", &N, &M); //���ؿ����� scanf_s�� �������  ���ϳ�?
	go(0);
	return 0;
}