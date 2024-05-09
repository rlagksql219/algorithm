#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> s;
int ans = 0;

void sol(int x, int y) {
	if (s.empty())	s.push({ x, y });
	else {
		if (s.top().second < y)	s.push({ x, y });
		else {
			while (!s.empty() && s.top().second > y) {
				s.pop();
				ans++;
			}
			if (!s.empty() && s.top().second != y)	s.push({ x,y });
			if (s.empty())	s.push({ x, y });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		sol(x, y);
	}

	while (!s.empty()) {
		if (s.top().second != 0) ans++;
		s.pop();
	}

	cout << ans;

	return 0;
}