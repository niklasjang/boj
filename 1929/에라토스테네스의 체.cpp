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
���ش��� �˷��� �����佺 �׳׽��� ü�� ����Ѵ�.

int prime[100]; // �Ҽ� ����
int pn=0; // �Ҽ��� ����
bool check[101]; // ���������� true , �������� ���� : false

int n = 100; // 100���� �Ҽ�
	for (int i=2; i<=n; i++) {                // i<=n�� �ƴ� i*i�� �ص� ������ ��� check �迭�� �����ؼ� true/false�� �Ǻ��ؾ��ϸ� i<=n�� ����.
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i*i; j<=n; j+=i) {   // int j = i*i�� ���������� �´� �ڵ������� i�� ����� ū ���� ���� int���� �ʰ��Ǽ� i+i �Ǵ� i*2�� ����ϰ� �Ѵ�.
				check[j] = true;
			}
		}
	}
}
.
*/
#include <iostream>
using namespace std;

const int MAX = 1000000;
bool color[MAX+1]; //�� +1����? //true : ������. false : �������� ����

int main() {
	color[0] = color[1] = true; //���� �ø�
	for (int i = 2; i*i<= MAX; i++) {
		if (color[i] == false) {
			/*
			if (M <= i) {
				cout << i << endl;
				//prime[pn++] = i;
			}
			*/
			
			for (int j = i + i; j <= MAX; j += i) { //long long j = i*i�ص� �ǳ�?
				color[j] = true;
			}
		}
	}

	//int prime[MAX];
	int M, N;
	cin >> M >> N;

	for (int i = M; i < N + 1; i++) {
		if (color[i] == false)
			cout << i << '\n';
	}
	return 0;
}