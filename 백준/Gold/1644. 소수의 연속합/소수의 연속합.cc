#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[4000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int N;
	int ans = 0;
	cin >> N;

	arr[0] = 1; arr[1] = 1;
	for (int i = 2; i * i <= N; i++) {
		for (int j = 2; i * j <= N; j++) {
			arr[i * j] = 1;
		}
	}

	for (int i = 0; i <= N; i++) {
		if(arr[i] == 0)	v.push_back(i);
	}

	int start = 0, end = 0, sum = 0;
	while (end < v.size()) {
		if (sum < N) {
			sum += v[end];
			end++;
		}
		else {
			if (sum == N)	ans++;
			sum -= v[start];
			start++;
		}
	}

	if (find(v.begin(), v.end(), N) != v.end())	ans++;
	cout << ans;

	return 0;
}