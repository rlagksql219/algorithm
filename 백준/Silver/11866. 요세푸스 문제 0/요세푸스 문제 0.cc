#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	queue<int> q;
	cin >> n >> k;
	cout << "<";

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (!q.empty()) {
		if(q.size() != n)
			cout << ", ";
		for (int i = 0; i < k-1; i++) {
			int num = q.front();
			q.pop();
			q.push(num);
		}
		cout << q.front();
		q.pop();
	}
	cout << ">";

	return 0;
}