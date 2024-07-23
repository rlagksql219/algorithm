#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int ans = 0;
	cin >> N;

	vector<int> building(N);
	vector<int> cnt(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> building[i];
	}

	for (int i = 0; i < N; i++) {
		double max_level = -9999999999;
		for (int j = i + 1; j < N; j++) {
			double level = (double)(building[j] - building[i]) / (j - i);
			if (level > max_level) {
				cnt[i]++;
				cnt[j]++;
				max_level = level;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, cnt[i]);
	}

	cout << ans;

	return 0;
}