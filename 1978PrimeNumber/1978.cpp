/*
20109-03-15

����
�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.

���
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.

*/
#include <iostream>
using namespace std;

bool prime(int num) {
	//cout << "prime" << endl;
	if (num < 2) {
		//cout << "return false" << endl;
		return false;
	}
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) {
			//cout << "return false" << endl;
			return false;
		}
	}
	//cout << "return true" << endl;
	return true;
}
int main(void) {
	int arr[111];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	--i;
	N = 0;
	for (; i >= 0; i--) {
		//cout << "i is.." << arr[i] << endl;
		if (prime(arr[i])) {
			N += 1;
		}
	}

	cout << N << endl;
	return 0;
}