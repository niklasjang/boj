/*
2019-03-31
��ȯ��

����
����ִ� ������ S�� �־����� ��, �Ʒ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
remove x: S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
check x: S�� x�� ������ 1��, ������ 0�� ����Ѵ�.
toggle x: S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
all: S�� {1, 2, ..., 20} ���� �ٲ۴�.
empty: S�� ���������� �ٲ۴�.
�Է�
ù° �ٿ� �����ؾ� �ϴ� ������ �� M (1 �� M �� 3,000,000)�� �־�����.

��° �ٺ��� M���� �ٿ� �����ؾ� �ϴ� ������ �� �ٿ� �ϳ��� �־�����.

���
check ������ �־���������, ����� ����Ѵ�.

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