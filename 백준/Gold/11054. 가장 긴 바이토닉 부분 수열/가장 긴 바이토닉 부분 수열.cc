#include <iostream>
#include <vector>

using namespace std;

int dp[1001];
int dp2[1001];

int main() {
	int N;
	vector<int> v;
	int ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++) { //입력
		int tmp;

		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < N; i++) { //증가
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (v[i] > v[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	for (int i = N - 1; i >= 0; i--) { //감소
		dp2[i] = 1;

		for (int j = N - 1; j > i; j--) {
			if (v[i] > v[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}

	for (int i = 0; i < N; i++) { //answer
		ans = max(ans, dp[i] + dp2[i] - 1);
	}

	cout << ans;

	return 0;
}