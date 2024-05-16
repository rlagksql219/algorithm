#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int ans = 0;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < v.size(); i++) {
		int target = v[i];
		for (int j = 0; j < v.size(); j++) {
			if (i == j)	continue;

			if (find(v.begin(), v.end(), target - v[j]) != v.end()) {
				int index = find(v.begin(), v.end(), target - v[j]) - v.begin();
				if (index != i && index != j) {
					ans++;
					break;
				}

				if (find(v.begin() + index + 1, v.end(), target - v[j]) != v.end()) {
					int index2 = find(v.begin() + index + 1, v.end(), target - v[j]) - v.begin();
					if (index2 != i && index2 != j) {
						ans++;
						break;
					}
				}

			}
		}
	}

	cout << ans;

	return 0;
}