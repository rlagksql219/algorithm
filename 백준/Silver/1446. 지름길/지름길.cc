#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, D;
	cin >> N >> D;
	vector<int> v(D + 1, 999999999);
	vector<pair<int, int>> route[10001];
	for (int i = 0; i < N; i++) {
		int start, end, len;
		cin >> start >> end >> len;
		route[end].push_back({ start, len });
	}
	
	v[0] = 0;
	for (int i = 1; i <= D; i++) {
		v[i] = v[i - 1] + 1;
		for (int j = 0; j < route[i].size(); j++) {
			v[i] = min(v[i], v[route[i][j].first] + route[i][j].second);
		}
	}

	cout << v[D];

	return 0;
}