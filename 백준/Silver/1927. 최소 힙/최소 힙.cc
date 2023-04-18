#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;

		cin >> tmp;
		if (tmp > 0) {
			pq.push(tmp);
		}
		else {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				cout << 0 << '\n';
		}
	}

	return 0;
}