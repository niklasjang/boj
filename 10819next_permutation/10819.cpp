/*
2019-03-21
장환석
문제
N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

입력
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 8;
int arr[MAX];
int N;

int GetAbsolute(int x, int y) {
	if (x >= y) {
		//cout << x << "-" << y << endl;
		return x - y;
	}
	else {
		//cout << y << "-" << x << endl;
		return y - x;
	}
}

int main(void) {
	int ans = 0, abs = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, &arr[N]);
	do {
		abs = 0;
		for (int i = 0; i < N-1; i++) {
			abs += GetAbsolute(arr[i], arr[i+1]);
		}
		//cout << "abs is..." << abs<<endl;
		if (abs > ans) {
			ans = abs;
		}
		
	} while (next_permutation(arr, &arr[N]));
	cout << ans << "\n";	
	return 0;
}