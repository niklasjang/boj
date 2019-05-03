/*
2019-03-14
niklasjang 장환석


문제
양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다. 
각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1000000을 넘지 않는다.

출력
각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.


답지 9613.cpp 파일을 보고 다시 작성해본 파일

출력값의 type이 int형이면 틀리고 long long형이면 맞다고 채점이 된다!!

*/

#include <iostream>
using namespace std;

int gcd(int x, int y) {
	/*
	GCD 함수 : 유클리드 호제법
	설명 : GCD(a,b) = GCD(b,a%b)이고, GCD(x,y)에서 y가 0일 때 x와 y의 GCD는 x이다.
	*/
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main(void) {
	/*
	문제를 매우 간단하게 풀이합니다. pair<int,int>나 list<<pair<int,int>> type을 사용하면 복잡해질 뿐입니다. 간단한 문제는 배열을 사용해서 풀이하는 것이 좋습니다.
	*/
	int testCase, n;
	long long result = 0;
	int arr[111];

	cin >> testCase;
	while (testCase--) {
		cin >> n;
		for (int i = 0; i < n;i++) {
			cin >> arr[i];
		}
		result = 0; // //여기에서 long long을 사용합니다. int형을 사용하면 표현 가능 범위를 넘어설 수 있습니다. 
		for (int j = 0; j < n - 1; j++) {
			for (int k = j+1; k < n; k++) {
				result += gcd(arr[j], arr[k]);
			}
		}
		cout << result << endl;
	}
	return 0;
}