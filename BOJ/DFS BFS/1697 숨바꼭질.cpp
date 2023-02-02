#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[100001];

void bfs(int node) {
	queue<pair<int, int>> q;
	q.push({ node, 0 });

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == K) {
			cout << cnt;
			break;
		}

		if (x + 1 >= 0 && x + 1 < 100001 && !visited[x+1]) {
			visited[x + 1] = true;
			q.push({ x + 1, cnt + 1 });
		}
		if (x - 1 >= 0 && x - 1 < 100001 && !visited[x - 1]) {
			visited[x - 1] = true;
			q.push({ x - 1, cnt + 1 });
		}
		if (x * 2 >= 0 && x * 2 < 100001 && !visited[x * 2]) {
			visited[x * 2] = true;
			q.push({ x * 2, cnt + 1 });
		}
	}
}

int main() {

	cin >> N >> K;
	visited[N] = true;
	bfs(N);

	return 0;
}