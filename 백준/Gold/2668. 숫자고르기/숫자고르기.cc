#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[101];
bool visited[101];
bool done[101];
vector<int> ans;

void dfs(int node) {
	visited[node] = true;
	int next = arr[node];
	if (!visited[next])	dfs(next);
	else if (!done[next]) {
		for (int i = next; i != node; i = arr[i]) {
			ans.push_back(i);
		}
		ans.push_back(node);
	}
	done[node] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		if (i == arr[i]) {
			ans.push_back(i);
			visited[i] = true;
			done[i] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i])	dfs(i);
	}


	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}