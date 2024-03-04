#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d, k, c;
	vector<int> v;
	cin >> n >> d >> k >> c;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		vector<int> cnt(d + 1);
		for (int j = 0; j < k; j++) {
			int index = (i + j) % n;
			if (v[index] == c)	continue;
			cnt[v[index]]++;
		}

		int total = 0;
		for (int j = 1; j <= d; j++) {
			if (cnt[j] > 0)
				total++;
		}
		ans = max(total, ans);
	}

	cout << ++ans;

	return 0;
}