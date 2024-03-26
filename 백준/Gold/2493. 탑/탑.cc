#include <iostream>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	stack<pair<int, int>> s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		
		while (!s.empty()) {
			if (tmp <= s.top().second) { //수신탑 찾은 경우
				cout << s.top().first << " ";
				break;
			}

			s.pop();
		}
		if (s.empty())
			cout << 0 << " ";

		s.push({ i + 1, tmp });
	}

	return 0;
}