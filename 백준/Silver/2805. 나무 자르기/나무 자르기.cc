#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, M;
	long long ans = 0;
	vector<int> tree;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		tree.push_back(tmp);
	}
	sort(tree.begin(), tree.end());
	
	long long start = 0;
	long long end = tree.back();

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long home = 0;

		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) {
				home += tree[i] - mid;
			}
		}

		if (home >= M) {
			start = mid + 1;
			ans = mid;
		}
		else {
			end = mid - 1;
		}
	}

	cout << ans;

	return 0;
}