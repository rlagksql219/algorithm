#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int N;
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		long long tmp;
		cin >> tmp;
		pq.push(tmp);
		if (pq.size() > N)	pq.pop();
	}

	cout << pq.top();

	return 0;
}