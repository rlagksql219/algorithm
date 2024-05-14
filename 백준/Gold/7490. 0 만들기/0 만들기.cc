#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> ans;


void solve(int target, int sum, int sign, int prev, int idx, string expression) {
	if (idx == target) {
		sum += (prev * sign);

		if (sum == 0)
			ans.push_back(expression);
		return;
	}
	else {
		// +
		solve(target, sum + (prev * sign), 1, idx + 1, idx + 1, expression + '+' + to_string(idx + 1));

		// -
		solve(target, sum + (prev * sign), -1, idx + 1, idx + 1, expression + '-' + to_string(idx + 1));

		// 공백으로 계산
		solve(target, sum, sign, prev * 10 + (idx + 1), idx + 1, expression + ' ' + to_string(idx + 1));
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;
		solve(num, 0, 1, 1, 1, "1");
		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
		cout << '\n';
		ans.clear();
	}

	return 0;
}