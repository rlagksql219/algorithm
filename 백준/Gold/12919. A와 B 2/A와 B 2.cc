#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
int mark;

void bfs(string str) {
	queue<string> q;
	q.push(str);

	while (!q.empty()) {
		string x = q.front();
		q.pop();

		if (x == s) {
			mark = 1;
			break;
		}

		if (x.length() < s.length()) {
			break;
		}
		else {
			if (x.back() == 'A') {
				string tmp1 = x;
				tmp1.erase(tmp1.begin() + tmp1.length() - 1);
				q.push(tmp1);
			}
			if (x.front() == 'B') {
				string tmp2 = x;
				reverse(tmp2.begin(), tmp2.end());
				tmp2.erase(tmp2.begin() + tmp2.length() - 1);
				q.push(tmp2);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> t;
	bfs(t);
	cout << mark;

	return 0;
}