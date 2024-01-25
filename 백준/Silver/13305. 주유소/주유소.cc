#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<long long> dist(N-1);
	vector<long long> price(N);
	vector<long long> min_price(N);
	long long ans = 0;

	for (int i = 0; i < N - 1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}

	min_price[0] = price[0];
	for (int i = 1; i < N; i++) {
		min_price[i] = min(min_price[i - 1], price[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		ans += dist[i] * min_price[i];
	}

	cout << ans;

	return 0;
}