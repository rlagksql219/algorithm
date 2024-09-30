#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<pair<int, int>> v[20001];
int dist[20001];
bool visited[20001];

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
			int next = v[cur][i].first;
			int new_cost = cost + v[cur][i].second;
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

	int V, E, K;
	cin >> V >> E >> K;

	for (int i = 0; i <= V; i++) {
		dist[i] = INT_MAX;

	}

	for (int i = 0; i < E; i++) {
		int from, to, cnt;
		cin >> from >> to >> cnt;
		v[from].push_back({to, cnt});
	}

	dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX)	cout << "INF" << '\n';
		else {
			cout << dist[i] << '\n';
		}
	}

	return 0;
}