#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	vector<int> v;

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0)	v.push_back(i);
	}

	sort(v.begin(), v.end());
	if (v.size() < K)	cout << 0;
	else {
		cout << v[K - 1];
	}

	return 0;
}