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
		dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]); //i번째 잔을 마셨을 때, (i-1)번째 잔을 마신 경우와 안 마신 경우 중에 최댓값
		dp[i] = max(dp[i - 1], dp[i]); //i번째 잔을 마신 경우와 안 마신 경우 중에 최댓값
	}

	cout << dp[n-1];
	
	return 0;
}
