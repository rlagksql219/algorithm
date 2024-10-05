#include <iostream>
#include <string>

using namespace std;

int N;
string ans;
bool found;

void dfs(string str, int depth) {
	if (found)	return;

	//규칙검사
	for (int i = 1; i <= str.length() / 2; i++) {
		if (str.substr(str.length() - i, i) == str.substr(str.length() - 2 * i, i))
			return;
	}

	if (depth == N) {
		ans = str;
		found = true;
		return;
	}
	
	dfs(str + "1", depth + 1);
	dfs(str + "2", depth + 1);
	dfs(str + "3", depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dfs("", 0);

	cout << ans;

	return 0;
}