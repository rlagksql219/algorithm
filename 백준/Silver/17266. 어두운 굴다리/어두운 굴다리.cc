#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> v(M);
	double h = 0;
	for (int i = 0; i < M; i++) {
		cin >> v[i];
	}

	if (M == 1)	h = N;
	else {
		h = fmax(v.front(), N - v.back());
		for (int i = 0; i < M - 1; i++) {
			h = fmax(h, ceil((v[i + 1] - v[i]) / 2.0));
		}
	}

	cout << (int)h;

	return 0;
}