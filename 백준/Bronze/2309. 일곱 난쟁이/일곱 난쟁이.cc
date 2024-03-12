#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<int> arr) {
	int sum = 0;

	for (int i = 0; i < 7; i++) {
		sum += arr[i];
	}

	if (sum == 100) {
		for (int i = 0; i < 7; i++) {
			cout << arr[i] << '\n';
		}
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;

	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	do {
		if (check(v))	break;
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}