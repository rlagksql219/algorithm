#include <iostream>
#include <algorithm>

using namespace std;

/*
https://velog.io/@rlagksql219/BOJC-2579-%EA%B3%84%EB%8B%A8-%EC%98%A4%EB%A5%B4%EA%B8%B0
*/

int main() {
	int N;
	int stairs[300];
	int dp[300];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stairs[i];
	}

	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
	}

	cout << dp[N - 1];

	return 0;
}