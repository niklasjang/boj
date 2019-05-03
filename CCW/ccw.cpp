/*
2019-03-13
niklasjang ��ȯ��
���� �ذ� ��� ���ǳ�Ʈ 2 ���ʼ���.pdf

Counter Clock Wise �˰���
������ ������ ����ؼ� �� ������ �����ϴ���, �������� �ʴ����� �Ǻ��Ѵ�.

���� 
�� �� A(x1,y1), B(x2,y2), C(x3,y3)�� ���� �� ����AB�� ���� AC�� ������ ������ ���Ѵ�.
���� ����/������ ������ ���� +/-�̶�� �� ��, ������ ����� +(���� ��)�Ǵ�-(���� ��)�� ����� �� �ִ�.

���� �� A,B,C,D�� ���� �� ����AB�� ���ؼ� �� C�� �� D�� ������ ������ ����� ���� �����̰�,
���� CD�� ���ؼ� �� A�� ��B�� ������ ������ ����� ���� �����̸� �� ���� AB�� ���� CD�� �����Ѵ�.

���� :
�� ���� ���� �ϳ��� ����(������ ����) ���� �־
1. �� ���� ��ġ�� ���
2. �ټ��� ���� ��ġ�� ��� (�� ������ ��ħ)
3. �� ������ ���� ��ġ�� ����
4. �ϳ��� ������ �ٸ� ���п� �����ϴ� ���
���� ���� CCW �˰����� ����� �� ����. 
*/
#include <iostream>
using namespace std;

int myccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int result = x1*y2 + x2*y3 + x3*y1;
	result -= x1 * y3 + x2 * y1 + x3 * y2;
	if (result > 0) {
		return 1;
	}
	else if (result < 0) {
		return -1;
	}
	else { //�� ������ ��ġ�� ���
		return 0;
	}
}
int main() {
	pair<int, int>A = make_pair(1,4);
	pair<int, int>B = make_pair(2,0);
	pair<int, int>C = make_pair(3,2);
	int result = myccw(A.first, A.second, B.first, B.second, C.first, C.second);
	cout << result << endl;

}