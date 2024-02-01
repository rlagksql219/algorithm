#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, X;
	vector<int> v;
	cin >> N >> X;
	vector<int> prefix_sum(N + 1, 0);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		prefix_sum[i + 1] = prefix_sum[i] + tmp;
	}

	int ans1 = 0, ans2 = 0;
	for (int i = X; i <= N; i++) {
		int sum = prefix_sum[i] - prefix_sum[i - X];

		if (sum > ans1) {
			ans1 = sum;
			ans2 = 1;
		}
		else if (sum == ans1) {
			ans2++;
		}
	}

	if (ans1 == 0)	cout << "SAD";
	else {
		cout << ans1 << '\n' << ans2;
	}

	return 0;
}