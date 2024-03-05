#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool visited[100001];

void bfs(int node) {
	queue<pair<int, int>> q;
	q.push({ node, 0 });

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == k) {
			cout << cnt;
			break;
		}

		if (x * 2 >= 0 && x * 2 < 100001 && !visited[x * 2]) {
			visited[x * 2] = true;
			q.push({ x * 2, cnt });
		}
		if (x - 1 >= 0 && x - 1 < 100001 && !visited[x - 1]) {
			visited[x - 1] = true;
			q.push({ x - 1, cnt + 1 });
		}
		if (x + 1 >= 0 && x + 1 < 100001 && !visited[x + 1]) {
			visited[x + 1] = true;
			q.push({ x + 1, cnt + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	visited[n] = true;
	bfs(n);

	return 0;
}