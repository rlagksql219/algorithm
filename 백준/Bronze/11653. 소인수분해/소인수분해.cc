#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> ans;

	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			ans.push_back(i);
			n /= i;
			i = 1;
		}
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}