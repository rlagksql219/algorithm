#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int ans = 0;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int end = 0;
	for (int start = 0; start < n; start++) {
		while (end < n && cnt[v[end]] < k) {
			cnt[v[end]]++;
			end++;
		}
		ans = max(ans, end - start);

		if (end == n)	break;

		cnt[v[start]]--;
	}

	cout << ans;

	return 0;
}