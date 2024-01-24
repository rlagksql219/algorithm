#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<string, bool> list;
	vector<string> name;
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		list.insert({ str, true });
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;

		if (list[str]) {
			name.push_back(str);
			ans++;
		}
	}

	sort(name.begin(), name.end());
	cout << ans << '\n';
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << '\n';
	}

	return 0;
}