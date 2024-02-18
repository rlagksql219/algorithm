#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	unordered_set<string> keyword;
	cin >> N >> M;
	int ans = N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		keyword.insert(tmp);
	}
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		stringstream ss(str);
		string tmp;

		while (getline(ss, tmp, ',')) {
			if (keyword.find(tmp) != keyword.end()) { //find
				keyword.erase(keyword.find(tmp));
				ans--;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}