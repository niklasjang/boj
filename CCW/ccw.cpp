/*
2019-03-13
niklasjang 장환석
문제 해결 기법 강의노트 2 기초수학.pdf

Counter Clock Wise 알고리즘
외적의 개념을 사용해서 두 선분이 교차하는지, 교차하지 않는지를 판별한다.

설명 
세 점 A(x1,y1), B(x2,y2), C(x3,y3)가 있을 때 선분AB와 선분 AC의 외적의 방향을 구한다.
들어가는 방향/나오는 방향을 각각 +/-이라고 할 때, 외적의 결과를 +(양의 값)또는-(음의 값)로 출력할 수 있다.

이제 점 A,B,C,D가 있을 때 선분AB에 대해서 점 C와 점 D의 각각의 외적의 결과의 곱이 음수이고,
선분 CD에 대해서 점 A와 점B의 각각의 외적의 결과의 곱이 음수이면 두 선분 AB와 선불 CD는 교차한다.

예외 :
네 개의 점이 하나의 직선(무한한 선분) 위에 있어서
1. 한 점이 겹치는 경우
2. 다수의 점이 겹치는 경우 (두 선분이 겹침)
3. 두 선분이 서로 겹치지 않음
4. 하나의 선분이 다른 선분에 포함하는 경우
에는 위의 CCW 알고리즘을 사용할 수 없다. 
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
	else { //두 선분이 겹치는 경우
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