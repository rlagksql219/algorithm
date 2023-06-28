#include <iostream>
#include <vector>

using namespace std;

int dp[1001];

int main() {
	int N;
	vector<int> v;
	int ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;

		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		dp[i] = v[i];
		
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				if (dp[i] < dp[j] + v[i])
					dp[i] = dp[j] + v[i];
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}
