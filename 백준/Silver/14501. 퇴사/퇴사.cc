#include <iostream>
#include <algorithm>

using namespace std;

int t[16];
int p[16];
int dp[16];

int main() {
	int N;
	
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> t[i] >> p[i];

	for (int i = N; i > 0; i--) {
		if ((i + t[i] - 1) > N)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
	}

	cout << dp[1];

	return 0;
}