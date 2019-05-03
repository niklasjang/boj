/*
2019-03-20
장환석

Next permutation을 구현해보자.

문제
1부터 N까지의 수로 이루어진 순열이 있다. 이때, 사전순으로 다음에 오는 순열을 구하는 프로그램을 작성하시오.

사전 순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은 내림차순으로 이루어진 순열이다.

N = 3인 경우에 사전순으로 순열을 나열하면 다음과 같다.

1, 2, 3
1, 3, 2
2, 1, 3
2, 3, 1
3, 1, 2
3, 2, 1
입력
첫째 줄에 N(1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄에 순열이 주어진다.

출력
첫째 줄에 입력으로 주어진 순열의 다음에 오는 순열을 출력한다. 만약, 사전순으로 마지막에 오는 순열인 경우에는 -1을 출력한다.

*/

#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int *arr = new int[N];

	int i = 0;
	// 수열 입력
	for (; i < N; i++) {
		cin >> arr[i];
	}

	//내림차순 시작하는 지점을 i로
	i = N - 1;
	while (i > 0 && arr[i - 1] >= arr[i]) {
		i -= 1;
	}
	//이미 마지막 순열이면 return -1
	if (i <= 0) {
		cout << "-1\n";
		return 0;
	}

	int j = N- 1;
	while (arr[j] <= arr[i - 1]) {
		j -= 1;
	}

	int temp = arr[j];
	arr[j] = arr[i-1];
	arr[i-1] = temp;

	j = N - 1;
	while (i < j) {
		int temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
		i += 1;
		j -= 1;
	}

	for (int i = 0; i < N ; i++) {
		cout << arr[i]<<" ";
	}
	cout << "\n";
	return 0;
}