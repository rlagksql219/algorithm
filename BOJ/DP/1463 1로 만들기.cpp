#include <iostream>
#include <algorithm>

using namespace std;

/*
https://velog.io/@rlagksql219/BOJC-1463-1%EB%A1%9C-%EB%A7%8C%EB%93%A4%EA%B8%B0-DP
*/

int dp[1000000];

int main() {
	int N;

	cin >> N;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N];

	return 0;
}