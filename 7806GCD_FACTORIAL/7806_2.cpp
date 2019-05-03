/*
2019-03-13
niklasjang 장환석

두 수의 최대공약수는 두 수를 나머지 없이 나눌 수 있는 가장 큰 자연수로 정의한다. 예를 들어, 8과 12의 최대공약수는 GCD(8,12)로 나타내고, 그 값은 4이다. 4는 8과 12를 나눌 수 있는 가장 큰 정수이기 때문이다. (8과 12의 공약수는 1, 2, 4가 있다)

자연수의 팩토리얼은 그 수보다 작거나 같은 모든 양의 정수의 곱이다. 예를 들어, 5의 팩토리얼은 5!로 나타내고 1*2*3*4*5 = 120이다. (0!은 1로 정한다)

두 수 n과 k가 주어졌을 때, n!과 k의 최대공약수를 구하는 프로그램을 작성하시오. 예를 들어, n = 3, k = 10이라면, GCD(n!,k) = GCD(3!,10) = GCD(1*2*3,10) = GCD(6,10) = 2가 된다.

입력 : 각 줄에 n과 k가 하나씩 주어진다. (0 ≤ n ≤ 1,000,000,000, 1 ≤ k ≤ 1,000,000,000)

출력 : 입력의 각 줄에 대해서, n!과 k의 최대공약수를 출력한다.

풀이 :
10430의 moduler에서 배운 아래 식을 사용해서,
n! % k =( (n%k) * (n-1!%k) ) % k
 엄청 큰 수의 factorial을 구한 다음에 GCD를 구하는 것이 아니라 factorial을 구하는 과정에서 moduler를 사용해서
 큰 수의 연산이 필요없이 GCD를 구한다.

 메모리 초과로 틀렸다고 나옴 ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ

 boolean 지웠고 깔끔하게 만들었지만 recursion을 쓰면 안되는 듯.
 즉, for문을 사용해서 풀어보자
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int factMoulder(int a, int b) {
	//factorial with moduler
	//cout << "factorial (" << a << "," << b << ")" << endl;
	if (a == 0)
		return 1;
	else {
		//cout << "a is.." << a << endl;
		//cout << "fact result is..." << result << endl;
		return (a % b * factMoulder(a - 1, b)) % b;
	}
}

int gcd(int a, int b) {
	//cout << "gcd (" << a << "," << b << ")" << endl;
	if (b == 0) //GCD(a!,b)에서 b가 0이면 a 가 GCD
		return a;
	else {
		return gcd(b, a%b);
	}
}

int main(void) {
	int a, b;
	cin >> a >> b;
	a = factMoulder(a, b);
	cout << gcd(b, a) << endl;;
	return 0;
}
