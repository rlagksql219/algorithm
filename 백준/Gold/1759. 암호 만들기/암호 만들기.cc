#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
string str;
string combination;
int mo, za;

void dfs(int start, int depth) {
	if (depth == L) {
		if (mo >= 1 && za >= 2) {
			for (char c : combination) {
				cout << c;
			}
			cout << '\n';
		}
		return;
	}

	for (int i = start; i < str.length(); i++) {
		combination += str[i];
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')	mo++;
		else {
			za++;
		}
		dfs(i + 1, depth + 1);
		if (combination.back() == 'a' || combination.back() == 'e' || combination.back() == 'i' || combination.back() == 'o' || combination.back() == 'u')	mo--;
		else {
			za--;
		}
		combination.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		str += c;
	}
	sort(str.begin(), str.end());
	
	dfs(0, 0);

	return 0;
}