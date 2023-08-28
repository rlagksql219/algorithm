#include <iostream>

using namespace std;

int prime[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//에라토스테네스의 체
	for (int i = 2; i * i <= 1000000; i++) {
		if (prime[i] == 0) {
			for (int j = 2 * i; j <= 1000000; j += i) {
				prime[j] = 1;
			}
		}
	}

	while (1) {
		int n;
		int mark = 0;
		cin >> n;
		if (n == 0)	break;

		for (int a = 3; a <= n / 2; a += 2) {
			if (prime[a] == 0 && prime[n - a] == 0) {
				cout << n << " = " << a << " + " << n - a << "\n";
				mark = 1;
				break;
			}
		}

		if (mark == 0)
			cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}