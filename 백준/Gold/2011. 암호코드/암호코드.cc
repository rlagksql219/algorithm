#include <iostream>
#include <string>

using namespace std;

int dp[5001];
int arr[5001];

int main() {
	string str;
	cin >> str;
	for (int i = 1; i <= str.size(); i++)
		arr[i] = str[i - 1] - '0';

	if (str.size() == 1 && str[0] == '0') {
		cout << 0;

		return 0;
	}
	else {
		dp[0] = 1;
		for (int i = 1; i <= str.size(); i++) {
			if (arr[i] >= 1 && arr[i] <= 9) {
				dp[i] = (dp[i - 1] + dp[i]) % 1000000;
			}

			if (i == 1)	continue;

			int tmp = arr[i] + arr[i - 1] * 10;
			if (tmp >= 10 && tmp <= 26) {
				dp[i] = (dp[i - 2] + dp[i]) % 1000000;
			}
		}
	}

	cout << dp[str.size()];

	return 0;
}