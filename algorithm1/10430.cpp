/*
2019-03-13
niklasjang 장환석

10430번
(A+B)%C는 (A%C + B%C)%C 와 같을까?

(A×B)%C는 (A%C × B%C)%C 와 같을까?

세 수 A, B, C가 주어졌을 때, 위의 네 가지 값을 구하는 프로그램을 작성하시오.

입력 :
첫째 줄에 A, B, C가 순서대로 주어진다. (2 ≤ A, B, C ≤ 10000)

출력 :
첫째 줄에 (A+B)%C, 둘째 줄에 (A%C + B%C)%C, 셋째 줄에 (A×B)%C, 넷째 줄에 (A%C × B%C)%C를 출력한다.
*/
#include <iostream>
using namespace std;
int main() {
	int A, B, C;
	cin>>A>>B>>C;
	cout << (A + B) % C << endl;
	cout << (A%C + B % C) % C << endl;
	cout << (A*B) % C << endl;
	cout << ((A%C) *(B%C)) % C << endl;
}
/*
메모리 더 적게 먹는 코드 : 1116KB
#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", (a + b) % c);
	printf("%d\n", (a % c + b % c) % c);
	printf("%d\n", (a * b) % c);
	printf("%d\n", (a % c * b % c) % c);
	return 0;
}
*/