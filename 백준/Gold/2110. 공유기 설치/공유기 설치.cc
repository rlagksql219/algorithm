#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	int ans = 0;
	vector<int> pos;

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		pos.push_back(tmp);
	}
	sort(pos.begin(), pos.end());
	
	int start = 1; //최소 거리
	int end = pos[N - 1] - pos[0]; //최대 거리

	while (start <= end) {
		int wifi = 1;
		int mid = (start + end) / 2;
		int st = pos[0];

		for (int i = 1; i < N; i++) {
			if (pos[i] - st >= mid) {
				wifi++;
				st = pos[i];
			}
		}

		if (wifi >= C) {
			ans = max(ans, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << ans;

	return 0;
}