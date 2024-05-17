#include <iostream>

using namespace std;

int sum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int ans = -987654321;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp;
	}

	for (int i = k; i <= n; i++) {
		ans = max(ans, (sum[i] - sum[i - k]));
	}

	cout << ans;

	return 0;
}