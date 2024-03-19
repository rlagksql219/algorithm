#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		vector<int> v[101];
		string str;
		int k;
		int m = 100001, M = -1;
		cin >> str >> k;
		for (int i = 0; i < str.length(); i++) {
			int num = str[i] - '0';
			v[num].push_back(i);
		}

		for (int i = 49; i <= 74; i++) { //a=49, z=74
			if (v[i].size() < k)	continue;
			for (int j = 0; j + k - 1 < v[i].size(); j++) {
				m = min(m, v[i][j + k - 1] - v[i][j]);
				M = max(M, v[i][j + k - 1] - v[i][j]);
			}
		}

		if (M == -1) {
			cout << -1 << '\n';
		}
		else {
			cout << m + 1 << " " << M + 1 << '\n';
		}
	}

	return 0;
}