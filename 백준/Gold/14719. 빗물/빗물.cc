#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int H, W;
	int ans = 0;
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			arr[j][i] = 1;
		}
	}

	for (int i = 0; i < H; i++) {
		vector<int> v;
		for (int j = 0; j < W; j++) {
			if (arr[i][j] == 1)
				v.push_back(j);
		}
		if (v.empty())	continue;
		for (int j = v.front() + 1; j < v.back(); j++) {
			if (find(v.begin(), v.end(), j) == v.end())
				ans++;
		}
	}

	cout << ans;

	return 0;
}