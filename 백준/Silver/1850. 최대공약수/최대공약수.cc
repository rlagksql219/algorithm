#include <iostream>

using namespace std;

/*
<유클리드 호제법>
정수 a, b (a>=b)
r = a % b

a와 b의 최대공약수 (a, b)
=> (a,b) = (b, r)


a와 b의 최소공배수
=> a * b / (a, b)
*/


long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	long long a, b;
	long long ans = 0; //최대공약수

	cin >> a >> b;
	
	if (a > b)
		ans = gcd(a, b);
	else
		ans = gcd(b, a);

	while (ans--)
		cout << 1;

	return 0;
}