#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		cout << upper_bound(v.begin(), v.end(), tmp) - lower_bound(v.begin(), v.end(), tmp) << " ";
	}

	return 0;
}