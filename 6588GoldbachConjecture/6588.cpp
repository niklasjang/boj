/*
2019-03-16
��ȯ��

����
1742��, ������ �Ƹ��߾� ���а� ũ����Ƽ�� ������� �����ϸ�Ʈ ���Ϸ����� ������ ���� ������ �����ϴ� ������ ���´�.

4���� ū ��� ¦���� �� Ȧ�� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
���� ��� 8�� 3 + 5�� ��Ÿ�� �� �ְ�, 3�� 5�� ��� Ȧ���� �Ҽ��̴�. ��, 20 = 3 + 17 = 7 + 13, 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23 �̴�.

�� ������ ������ �ذ���� ���� �����̴�.

�鸸 ������ ��� ¦���� ���ؼ�, �� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� �ϳ� �Ǵ� �� �̻��� �׽�Ʈ ���̽��� �̷���� �ִ�. �׽�Ʈ ���̽��� ������ 100,000���� ���� �ʴ´�.

�� �׽�Ʈ ���̽��� ¦�� ���� n �ϳ��� �̷���� �ִ�. (6 �� n �� 1000000)

�Է��� ������ �ٿ��� 0�� �ϳ� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ�, n = a + b ���·� ����Ѵ�. �̶�, a�� b�� Ȧ�� �Ҽ��̴�. ���ڿ� �����ڴ� ���� �ϳ��� ���еǾ��� �ִ�. 
����, n�� ���� �� �ִ� ����� ���� �������, b-a�� ���� ū ���� ����Ѵ�. ��, �� Ȧ�� �Ҽ��� ������ n�� ��Ÿ�� �� ���� ��쿡�� 
"Goldbach's conjecture is wrong."�� ����Ѵ�.
*/
#include <iostream>
using namespace std;

const int MAX = 1000000;
int primeArr[MAX];
int pn;
bool check[MAX];

int main(void) {
	ios_base::sync_with_stdio(false); //REMEMBERME ����
	cin.tie(nullptr);

	//�����佺�׳׽��� ü
	check[0] = check[1] = true;

	for (int i = 2; i*i <= MAX; i++) {
		if (check[i] == false) {
			primeArr[pn++] = i;
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	//�׽�Ʈ ���̽� �Է�
	int num;
	while (true) {
		cin >> num;

		//0�ԷµǸ� ����
		if (num == 0)
			break;

		for (int i = 1; i <pn; i++) {
			if (check[num - primeArr[i]] == false) {
				cout << num << " = " << primeArr[i] << " + " << num - primeArr[i] << "\n";
				break;
			}
			if(i == pn)
				cout << "Goldbach's conjecture is wrong." << "\n";
		}
	}
	return 0;
}