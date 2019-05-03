/*
2019-03-31
장환석

문제
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다.
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.
입력
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.

둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다.

#include <iostream>
#include <string>
using namespace std;
	
string func;
int M, N;
int main(void) {
	cin >> M;
	int s = 0;
	while (M--) {
		cin >> func;
		if (func == "add") {
			cin >> N;
			s = s | (1<<N-1);
		}
		else if (func == "remove") {
			cin >> N;
			s = s & ~(1 << N - 1);
		}
		else if (func == "check") {
			cin >> N;
			int res = s & (1 << N - 1);
			if (res) {
				cout <<"1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (func == "toggle") {
			cin >> N;
			s = s ^ (1 << N - 1);
		}
		else if (func == "all") {
			s = (1 << 20) - 1;
		}
		else if (func == "empty") {
			s = 0;
		}	
	}
	
	return 0;
}
*/
#include <cstdio>
#include <cstring>
using namespace std;
char b[111];
int main() {
	int n = 20;
	int m;
	scanf("%d", &m);
	int s = 0;
	int x;
	while (m--) {
		scanf("%s", b);
		if (!strcmp(b, "add")) {
			scanf("%d", &x); x--;
			s = (s | (1 << x));
		}
		else if (!strcmp(b, "remove")) {
			scanf("%d", &x); x--;
			s = (s & ~(1 << x));
		}
		else if (!strcmp(b, "check")) {
			scanf("%d", &x); x--;
			int res = (s & (1 << x));
			if (res) {
				puts("1");
			}
			else {
				puts("0");
			}
		}
		else if (!strcmp(b, "toggle")) {
			scanf("%d", &x); x--;
			s = (s ^ (1 << x));
		}
		else if (!strcmp(b, "all")) {
			s = (1 << n) - 1;
		}
		else if (!strcmp(b, "empty")) {
			s = 0;
		}
	}
	return 0;
}