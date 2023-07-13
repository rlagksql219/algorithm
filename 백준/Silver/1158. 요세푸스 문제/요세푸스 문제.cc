#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	vector<int> v;
	vector<int> mark;
	vector<int> ans;
	int cursor = -1;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		mark.push_back(0);
	}

	while (ans.size() != n) {
		for (int i = 0; i < k; i++) {
			cursor++;
			if (cursor >= n) {
				cursor -= n;
			}

			if (mark[cursor] == 1) {
				while (mark[cursor] == 1) {
					cursor++;
					if (cursor >= n) {
						cursor -= n;
					}
				}
			}
		}
		
		mark[cursor] = 1;
		ans.push_back(v[cursor]);
	}

	cout << "<";
	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1)
			cout << ans[i] << ">";
		else
			cout << ans[i] << ", ";
	}

	return 0;
}