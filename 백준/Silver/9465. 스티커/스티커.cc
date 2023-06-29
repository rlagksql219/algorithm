#include <iostream>
#include <vector>

using namespace std;

int dp[2][100001];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		vector<int> v[2];
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				int tmp;
				cin >> tmp;
				v[i].push_back(tmp);
			}
		}

		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = v[0][0];
		dp[1][1] = v[1][0];
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + v[0][i-1];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + v[1][i-1];
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}

	return 0;
}