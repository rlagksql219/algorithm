#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
int ans;
vector<string> v;
bool alpha[26];

void dfs(int idx, int remain) {
	if (remain == 0) {
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			string elem = v[i];
			bool flag = true;
			for (int j = 0; j < elem.size(); j++) {
				char ch = elem[j];
				if (!alpha[ch - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		ans = max(ans, cnt);
		if (ans == N) {
			cout << N << '\n';
			exit(0);
		}
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alpha[i])	continue;
		alpha[i] = true;
		dfs(i, remain - 1);
		alpha[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str.substr(4, str.length() - 8));
	}

	if (K < 5) {
		cout << 0 << '\n';
		return 0;
	}

	alpha[0] = true; //a
	alpha[2] = true; //c
	alpha[8] = true; //i
	alpha[13] = true; //n
	alpha[19] = true; //t

	dfs(0, K - 5);
	cout << ans << '\n';

	return 0;
}