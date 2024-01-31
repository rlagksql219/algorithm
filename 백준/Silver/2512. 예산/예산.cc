#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int N, MAX;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> MAX;
	sort(v.begin(), v.end());
	
	int start = 0;
	int mid = 0;
	int end = v.back();
	int sum = 0;

	while (start <= end) {
		sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			sum += min(v[i], mid);
		}

		if (MAX >= sum) {
			start = ++mid;
		}
		else {
			end = --mid;
		}
	}

	cout << end;

	return 0;
}