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


int gcd(int a, int b) {
	if (b == 0)	
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	int T;
	int n1, n2;
	int ans1 = 0; //최대공약수
	int ans2 = 0; //최소공배수

	cin >> T;
	while (T--) {
		cin >> n1 >> n2;
		if (n1 > n2)
			ans1 = gcd(n1, n2);
		else
			ans1 = gcd(n2, n1);

		ans2 = n1 * n2 / ans1;

		cout << ans2 << '\n';
	}

	return 0;
}