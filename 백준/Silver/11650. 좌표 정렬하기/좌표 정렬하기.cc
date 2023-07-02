#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	vector<pair<int, int>> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}