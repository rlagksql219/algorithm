#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main() {
	int n;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	dp[0] = v[0];
	dp[1] = dp[0] + v[1];
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[n-1];
	
	return 0;
}