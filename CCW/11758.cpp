/*
2019-03-13
niklasjang ��ȯ��
*/

#include <iostream>
using namespace std;

int myccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int result = x1 * y2 + x2 * y3 + x3 * y1;
	result -= x1 * y3 + x2 * y1 + x3 * y2;
	if (result > 0) { //ccw : ���鿡�� ������ ����
		return 1;
	}
	else if (result < 0) { //cw : �������� ���� ����
		return -1;
	}
	else { //�� ������ ����/��ġ�� ���
		return 0;
	}
}
int main() {
	pair<int, int>A;
	pair<int, int>B;
	pair<int, int>C;
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;

	int result = myccw(A.first, A.second, B.first, B.second, C.first, C.second);
	cout << result << endl;

}