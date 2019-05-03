/*
2019-03-14
niklasjang 장환석


문제
양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다. 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1000000을 넘지 않는다.

출력
각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.



출력값의 type이 int형이면 틀리고 long long형이면 맞다고 채점이 된다!!


*/
#include <iostream>
using namespace std;
int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}
int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int arr[111];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << endl;
	}
	return 0;
}