#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<int> v[300001];
int dist[300001];
bool visited[300001];

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

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	for (int i = 0; i <= N; i++) {
		dist[i] = INT_MAX;

	}

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}

	dijkstra(X);

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cout << i << '\n';
			cnt++;
		}
	}
	if (cnt == 0)	cout << "-1" << '\n';

	return 0;
}