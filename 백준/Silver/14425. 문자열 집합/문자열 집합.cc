#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<string, bool> m;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		m.insert({ str, 1 });
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (m[str])	ans++;
	}

	cout << ans;

	return 0;
}