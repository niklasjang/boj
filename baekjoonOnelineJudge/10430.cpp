/*
2019-03-13
niklasjang ��ȯ��

10430��
(A+B)%C�� (A%C + B%C)%C �� ������?

(A��B)%C�� (A%C �� B%C)%C �� ������?

�� �� A, B, C�� �־����� ��, ���� �� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է� :
ù° �ٿ� A, B, C�� ������� �־�����. (2 �� A, B, C �� 10000)

��� :
ù° �ٿ� (A+B)%C, ��° �ٿ� (A%C + B%C)%C, ��° �ٿ� (A��B)%C, ��° �ٿ� (A%C �� B%C)%C�� ����Ѵ�.
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
�޸� �� ���� �Դ� �ڵ� : 1116KB
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