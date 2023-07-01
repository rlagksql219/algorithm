#include <iostream>
#include <vector>

using namespace std;

int dp[1001];

int main() {
	int N;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		dp[i + 1] = tmp;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << dp[N];

	return 0;
}