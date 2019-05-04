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
백준님이 알려준 에라토스 테네스의 체를 사용한다.

int prime[100]; // 소수 저장
int pn=0; // 소수의 개수
bool check[101]; // 지워졌으면 true , 지워지지 않음 : false

int n = 100; // 100까지 소수
	for (int i=2; i<=n; i++) {                // i<=n가 아닌 i*i를 해도 되지만 모든 check 배열에 접근해서 true/false를 판별해야하면 i<=n를 쓴다.
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i*i; j<=n; j+=i) {   // int j = i*i가 개념적으로 맞는 코드이지만 i에 충분히 큰 수가 들어가면 int형이 초과되서 i+i 또는 i*2를 사용하곤 한다.
				check[j] = true;
			}
		}
	}
}
.
*/
#include <iostream>
using namespace std;

const int MAX = 1000000;
bool color[MAX+1]; //왜 +1이지? //true : 지워짐. false : 지워지지 않음

int main() {
	color[0] = color[1] = true; //여기 올림
	for (int i = 2; i*i<= MAX; i++) {
		if (color[i] == false) {
			/*
			if (M <= i) {
				cout << i << endl;
				//prime[pn++] = i;
			}
			*/
			
			for (int j = i + i; j <= MAX; j += i) { //long long j = i*i해도 되나?
				color[j] = true;
			}
		}
	}

	//int prime[MAX];
	int M, N;
	cin >> M >> N;

	for (int i = M; i < N + 1; i++) {
		if (color[i] == false)
			cout << i << '\n';
	}
	return 0;
}