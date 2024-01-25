#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
	if (a.second.first != b.second.first) { //cnt가 다른 경우
		return a.second.first > b.second.first;
	}
	else if (a.second.second != b.second.second) { //length가 다른 경우
		return a.second.second > b.second.second;
	}
	else { //그 외 경우는 사전순 정렬
		return a.first < b.first;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	map<string, pair<int, int>> m; //cnt, length
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str.length() >= M) {
			pair<int, int> p;
			int length = str.length();
			int cnt = 1;
			if (m.find(str) != m.end()) {
				cnt = m[str].first++;
			}
			p = { cnt, length };
			m.insert({ str, p });
		}
	}

	//sorting
	vector<pair<string, pair<int, int>>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << '\n';
	}

	return 0;
}