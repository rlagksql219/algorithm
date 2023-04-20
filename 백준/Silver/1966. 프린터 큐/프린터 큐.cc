#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		int ans = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			q.push({ i, tmp });
			pq.push(tmp);
		}

		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value) {
				pq.pop();
				ans++;
				if (index == M) {
					cout << ans << '\n';
					break;
				}
			}
			else
				q.push({ index, value });
		}
	}

	return 0;
}