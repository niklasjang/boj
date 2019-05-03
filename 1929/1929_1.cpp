/*
20109-03-15
장환석


문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.


풀이 :
모든 숫자에 대해서 prime인지 확인하는 알고리즘을 적용한다.
40번째 줄의 cout << i << "\n";를 cout<< i <<endl;로 고치면 시간 초과로 탈락한다.
*/
#include <iostream>
using namespace std;

bool prime(int num) {
	if (num < 2) {
		return false;
	}
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (prime(i))
			::cout << i << "\n";
	return 0;
}