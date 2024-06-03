#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long K, N;
	long long ans = 0;
	vector<int> v;

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	long long start = 1;
	long long end = v.back();

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;

		for (int i = 0; i < K; i++) {
			sum += v[i] / mid;
		}

		if (sum >= N) {
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