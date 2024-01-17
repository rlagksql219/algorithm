#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> v;

	cin >> N;
	while (N--) {
		string str;

		cin >> str;
		if (str == "add") {
			int num;
			cin >> num;
			if (find(v.begin(), v.end(), num) == v.end()) {
				v.push_back(num);
			}
		}
		else if (str == "remove") {
			int num;
			cin >> num;
			if (find(v.begin(), v.end(), num) != v.end()) {
				int index = find(v.begin(), v.end(), num) - v.begin();
				v.erase(v.begin() + index);
			}
		}
		else if (str == "check") {
			int num;
			cin >> num;
			if (find(v.begin(), v.end(), num) != v.end()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "toggle") {
			int num;
			cin >> num;
			if (find(v.begin(), v.end(), num) != v.end()) {
				int index = find(v.begin(), v.end(), num) - v.begin();
				v.erase(v.begin() + index);
			}
			else {
				v.push_back(num);
			}
		}
		else if (str == "all") {
			v.clear();
			for (int i = 1; i <= 20; i++) {
				v.push_back(i);
			}
		}
		else { //empty
			v.clear();
		}
	}

	return 0;
}