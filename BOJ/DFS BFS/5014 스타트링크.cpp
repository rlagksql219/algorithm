#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
bool visited[2000000];
int mark;

void bfs(int node) {
	queue<pair<int, int>> q;
	q.push({ node, 0 });

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == G) {
			cout << cnt;
			mark = 1;
			break;
		}

		if (x + U > 0 && x + U <= F && !visited[x + U]) {
			visited[x + U] = true;
			q.push({ x + U, cnt + 1 });
		}
		if (x - D > 0 && x - D <= F && !visited[x - D]) {
			visited[x - D] = true;
			q.push({ x - D, cnt + 1 });
		}
	}
}

int main() {

	cin >> F >> S >> G >> U >> D;
	visited[S] = true;
	bfs(S);
	
	if(mark == 0)
		cout << "use the stairs";

	return 0;
}