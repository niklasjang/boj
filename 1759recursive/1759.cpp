/*
2019-00-00
장환석
문제

암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다. 
또한 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다. 즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다.
C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.

입력
첫째 줄에 두 정수 L, C가 주어진다. (3 ≤ L ≤ C ≤ 15) 다음 줄에는 C개의 문자들이 공백으로 구분되어 주어진다. 주어지는 문자들은 알파벳 소문자이며, 중복되는 것은 없다.

출력
각 줄에 하나씩, 사전식으로 가능성 있는 암호를 모두 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAX = 15;
vector<char> alpha;
//vector<char>::iterator it;
char temp;
int C, L;

bool check(string password) {
	int mo = 0, za = 0;
	for (int i = 0; i < password.length(); i++) {
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') {
			mo++;
		}
		else {
			za++;
		}
	}
	if (mo >= 1 && za >=2) {
		return true;
	}
	else {
		return false;
	}
}

void go(int n, vector<char> &alpha, string password, int i) {
	if (password.length() == n) {
		if (check(password)) {
			cout << password << "\n";
		}
		return;
	}
	if (i >= alpha.size()) return;
	go(n, alpha, password + alpha[i], i+1);
	go(n, alpha, password, i+1);
}

int main(void) {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> temp;
		alpha.push_back(temp);
	}
	sort(alpha.begin(), alpha.end());
	go(L, alpha, "", 0);
	/*
	for (it = alpha.begin(); it != alpha.end(); ++it) {
		cout << *it << "\n";
	}*/
	
}
