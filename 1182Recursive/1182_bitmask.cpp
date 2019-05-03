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
	for (int i = 1; i < (1 << n); i++) { //00000..0000부터 11111...111111까지 여기서 0 또는 1 은 비트마스트에 해당 원소가 들어있는지(1) 아닌지(0) : 모든 경우에 대해서
		int sum = 0;
		for (int k = 0; k < n; k++) { //처음부터 끝까지 1이 들어있는 경우에 대해서
			if (i&(1 << k)) {
				sum += a[k]; //해당 값을 더해보고
			}
		}
		if (sum == s) { //s와 같으면
			ans += 1; //정답 count + 1;
 		}
	}
	cout << ans << '\n';
	return 0;
}