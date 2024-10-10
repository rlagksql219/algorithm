#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N;
	long long sum = 0;
	long long ans = 1;

	cin >> N;
	while (1) {
		if (sum + ans <= N) {
			sum += ans;
			ans++;
		}
		else {
			ans--;
			break;
		}
	}

	cout << ans;

	return 0;
}