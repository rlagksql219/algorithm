#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;
	int max_l = 0;
	int max_h = 0;
	int ans = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;
		v.push_back({ L, H });
		if (H > max_h) {
			max_h = H;
			max_l = L;
		}
	}
	sort(v.begin(), v.end());

	int cur_h = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].first == max_l)	break;

		if (cur_h < v[i].second) {
			ans += (max_l - v[i].first) * (v[i].second - cur_h);
			cur_h = v[i].second;
		}
	}

	cur_h = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i].first == max_l)	break;

		if (cur_h < v[i].second) {
			ans += (v[i].first - max_l) * (v[i].second - cur_h);
			cur_h = v[i].second;
		}
	}

	ans += max_h;

	cout << ans;

	return 0;
}