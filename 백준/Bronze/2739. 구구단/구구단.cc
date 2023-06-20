#include <iostream>

using namespace std;

int main() {
	int N;

	cin >> N;
	for (int i = 1; i <= 9; i++) {
		int ans = N * i;
		cout << N << " * " << i << " = " << ans << '\n';
	}

	return 0;
}