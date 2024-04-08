#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> v[50001];
int dist[50001];

void dijkstra(int start) {
	for (int i = 1; i <= n; i++) {
		dist[i] = 100000000001;
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
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
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 100000000;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	dijkstra(1);

	cout << dist[n];

	return 0;
}