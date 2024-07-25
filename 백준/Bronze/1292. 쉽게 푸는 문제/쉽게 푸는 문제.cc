#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int start, end;
	int ans = 0;
	vector<int> v;
	cin >> start >> end;
	for (int i = 1;; i++) {
		if (v.size() > end)	break;
		int num = i;
		while (num--) {
			v.push_back(i);
		}
	}

	for (int i = start - 1; i < end; i++) {
		ans += v[i];
	}

	cout << ans;

	return 0;
}