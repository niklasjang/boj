/*
2019-00-00
��ȯ��
����

��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� �����Ǹ� �ּ� �� ���� ������ �ּ� �� ���� �������� �����Ǿ� �ִٰ� �˷��� �ִ�. 
���� ��ȣ�� �̷�� ���ĺ��� ��ȣ���� �����ϴ� ������ �迭�Ǿ��� ���̶�� �����ȴ�. ��, abc�� ���ɼ��� �ִ� ��ȣ������ bac�� �׷��� �ʴ�.

�� ���� �ý��ۿ��� �������� ��ȣ�� ������� ���� ������ ������ C������ �ִٰ� �Ѵ�.
C���� ���ڵ��� ��� �־����� ��, ���ɼ� �ִ� ��ȣ���� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ���� L, C�� �־�����. (3 �� L �� C �� 15) ���� �ٿ��� C���� ���ڵ��� �������� ���еǾ� �־�����. �־����� ���ڵ��� ���ĺ� �ҹ����̸�, �ߺ��Ǵ� ���� ����.

���
�� �ٿ� �ϳ���, ���������� ���ɼ� �ִ� ��ȣ�� ��� ����Ѵ�.
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
