#include <iostream>

using namespace std;

bool arr[10][7] = { {true, true, true, false, true, true, true}, //0
					{false, false, true, false, false, false, true}, //1
					{false, true, true, true, true, true, false}, //2
					{false, true, true, true, false, true, true}, //3
					{true, false, true, true, false, false, true}, //4
					{true, true, false, true, false, true, true}, //5
					{true, true, false, true, true, true, true}, //6
					{false, true, true, false, false, false, true}, //7
					{true, true, true, true, true, true, true}, //8
					{true, true, true, true, false, true, true}}; //9

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, P, X;
	int ans = 0;
	cin >> N >> K >> P >> X;
	
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		int from = X, to = i;
		if (i == X)	continue;

		for (int j = 0; j < K; j++) {
			for (int k = 0; k < 7; k++) {
				if (arr[from % 10][k] != arr[to % 10][k])	cnt++;
			}
			from /= 10; to /= 10;
		}
		if (cnt <= P)	ans++;
	}

	cout << ans;

	return 0;
}