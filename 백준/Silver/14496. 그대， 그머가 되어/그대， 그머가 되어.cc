#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<int> v[1001];
int dist[1001];
bool visited[1001];

void dijkstra(int node) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, node });
	dist[node] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		if (visited[cur])	continue;
		visited[cur] = true;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			int new_cost = cost + 1;
			if (dist[next] > new_cost) {
				dist[next] = new_cost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, N, M;
	cin >> a >> b >> N >> M;

	for (int i = 0; i <= N; i++) {
		dist[i] = INT_MAX;

	}

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	dijkstra(a);
	if (dist[b] == INT_MAX)	cout << -1;
	else {
		cout << dist[b];
	}

	return 0;
}