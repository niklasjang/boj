/*
2019-03-23
장환석


문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.


*/

#include <iostream>
using namespace std;

int recursive(int sum, int goal) {
	
	int num = 0;
	if (sum > goal) {
		//정답을 찾을 수 없는 경우
		return 0;
	}
	else if (sum == goal) {
		//정답인 경우
		return 1;
	}
	else {
		//다시 호출해야하는 경우
		for (int i = 1; i < 4; i++) {
			num += recursive(sum + i, goal);
		}
	}
	return num;
}

int main(void) {
	int t = 0;
	cin >> t;
	
	while (t--) {
		int count = 0, sum = 0, goal=0;
		cin >> goal;
		cout << recursive(sum, goal) << "\n";
	}

	return 0;
}