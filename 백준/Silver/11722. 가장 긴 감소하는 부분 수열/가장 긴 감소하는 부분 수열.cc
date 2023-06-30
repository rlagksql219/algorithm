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
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j] > v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}