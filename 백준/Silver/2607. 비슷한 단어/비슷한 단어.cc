#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<char> v[101];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			v[i].push_back(str[j]);
		}
	}

	vector<int> target(26, 0);
	for (int j = 0; j < v[0].size(); j++) {
		target[v[0][j] - 'A']++;
	}

	for (int i = 1; i < N; i++) {
		int len_diff = v[i].size() - v[0].size();
		if (abs(len_diff) >= 2)	continue;


		vector<int> ascii(26, 0);
		int cnt = 0;
		vector<int> list;
		for (int j = 0; j < v[i].size(); j++) {
			ascii[v[i][j] - 'A']++;
		}
		for (int j = 0; j < 26; j++) {
			if (target[j] != ascii[j]) {
				cnt++;
				list.push_back(target[j] - ascii[j]);
			}
		}

		if (cnt == 0)	ans++;
		if (cnt == 1) { //한 문자를 더하거나 빼는 경우
			if (abs(list[0]) == 1)	ans++;
		}
		if (cnt == 2) { //한 문자를 다른 문자로 바꾸는 경우
			if (abs(list[0]) == 1 && abs(list[1]) == 1 && list[0] + list[1] == 0)	ans++;
		}
	}

	cout << ans;

	return 0;
}