#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<pair<int, int>> v[1001];
int dist[1001];
bool visited[1001];

void dijkstra(int node) {
	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
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
			int new_cost = v[cur][i].second + cost;
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

	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		dist[i] = INT_MAX;
	}

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({to, cost});
	}

	int start, destination;
	cin >> start >> destination;

	dijkstra(start);
	cout << dist[destination];

	return 0;
}