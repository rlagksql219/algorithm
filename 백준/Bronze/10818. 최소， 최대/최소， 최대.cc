#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;

		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	cout << v[0] << " " << v[n-1];

	return 0;
}