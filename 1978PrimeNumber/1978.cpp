/*
20109-03-15

문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.

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