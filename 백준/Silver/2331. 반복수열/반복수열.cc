#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[1001];

int main() {

	int a, p;
	int ans = 0;

	cin >> a >> p;
	dp[0] = a;
	for (int i = 1; ; i++) {
		int tmp = 0;
		string str = to_string(dp[i - 1]);
		for (int j = 0; j < str.size(); j++) {
			double result = pow(str[j] - '0', p);
			tmp += result;
		}

		dp[i] = tmp;
		if (find(dp, dp + i - 1, tmp) != dp + i - 1) {
			//동일 원소 찾음
			int index = find(dp, dp + i - 1, tmp) - dp;
			ans = index;
			break;
		}
	}

	cout << ans;

	return 0;
}