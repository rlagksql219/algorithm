#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<string> v;
	int ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == v[0])
			v.erase(v.begin());
		else {
			int index = 0;
			ans++;
			index = find(v.begin(), v.end(), str) - v.begin();
			v.erase(v.begin() + index);
		}
	}

	cout << ans;

	return 0;
}