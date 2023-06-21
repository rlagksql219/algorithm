#include <iostream>

using namespace std;

int dp[101][10];

int main() {
	int N;
	int ans = 0;

	cin >> N;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) //마지막 자리가 0이면 앞에 1만 가능
				dp[i][0] = dp[i - 1][j + 1];
			else if (j == 9) //마지막 자리가 9면 앞에 8만 가능
				dp[i][9] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans += dp[N][i];
		ans %= 1000000000;
	}
	cout << ans;

	return 0;
}