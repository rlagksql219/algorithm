#include <iostream>

using namespace std;

int main() {
	int N;
	int ans = 0;

	cin >> N;
	while (N >= 0) {
		if (N % 5 == 0) {
			ans += (N / 5);
			cout << ans;

			return 0;
		}
		else {
			N -= 3;
			ans++;
		}
	}

	cout << -1;

	return 0;
}