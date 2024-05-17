#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int ans = 0;
	cin >> n;

	int start = 1, end = 1, sum = 0;
	while (start <= end && end <= n) {
		if (sum < n) {
			sum += end;
			end++;
		}
		else {
			if (sum == n)	ans++;
			sum -= start;
			start++;
		}
	}

	cout << ans + 1;

	return 0;
}