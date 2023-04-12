#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> ans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		int index = 0;

		cin >> tmp;
		index = i - tmp;

		ans.insert(ans.begin()+index, i + 1);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}