#include <iostream>
using namespace std;
int a[20];
int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) { //00000..0000���� 11111...111111���� ���⼭ 0 �Ǵ� 1 �� ��Ʈ����Ʈ�� �ش� ���Ұ� ����ִ���(1) �ƴ���(0) : ��� ��쿡 ���ؼ�
		int sum = 0;
		for (int k = 0; k < n; k++) { //ó������ ������ 1�� ����ִ� ��쿡 ���ؼ�
			if (i&(1 << k)) {
				sum += a[k]; //�ش� ���� ���غ���
			}
		}
		if (sum == s) { //s�� ������
			ans += 1; //���� count + 1;
 		}
	}
	cout << ans << '\n';
	return 0;
}