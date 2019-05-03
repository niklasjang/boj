#include <iostream>
#include <list>
int main()
{
	std::list<int> A;
	std::list<int>::iterator it;
	A.push_back(1); A.push_back(2); A.push_back(3);
	for (it = A.begin(); it != A.end(); it++)
		std::cout << *it << std::endl;
	it = A.end(); it--;
	while (it != A.begin()) {
		std::cout << *it << std::endl;
		it--;
	}
	std::cout << *it << std::endl;
	return 0;
}
자연수  a,b,c에 대해서 ax +by = c 이 식은 c가 GCD(a,b)의 배수일 때만 정수해를 갖는다. 
따라서 소수 P와 P의 배수가 아닌 자연수 a에 대해서  ax+py =GCD(a,p)는 정수해를 갖는 것은 자명하다. 
a와 p는 서로소 관계이므로 ax+py = 1을 얻을 수 있다.
확장 유클리드 알고리즘은 GCD(a,b) = GCD(b,a%b)로 구할 수 있음을 의미한다.
a를 b로 나누었을 때 a = bq+r이라고 한다면 (bq+r)x + by = 1 = b(qx+y) + rx이기 때문이다. 
최종적인 GCD(a,b)는 GCD(b, a%b)에 대해 b가 1이거나 a%b의 결과가 0일 때 구할 수 있다. 두 조건을 만족하는 식은 다음과 같이 찾을 수 있다

ex1. GCD(11,5) = GCD(5, 11%5)
11%5 = 1 -> 11 - 5*2 = 1 -> 11*1 + 5*(-2) = 1 -> 음수이므로 양변 5*11더해서 답은 9
ex2. GCD(7,4) = GCD(4 ,7-4) = GCD(7-4, 4 % 4-(7-4)) -> 4-(7-4) = -7 + 4*2 = 1 따라서 답은 2.
