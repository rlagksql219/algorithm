#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	map<int, string> m;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		int tmp;
		cin >> s >> tmp;
		if (m.find(tmp) != m.end())	continue;
		m.insert({ tmp, s });
	}

	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		cout << m.lower_bound(tmp)->second << '\n';
	}

	return 0;
}