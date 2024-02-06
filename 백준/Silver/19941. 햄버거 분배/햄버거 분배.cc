#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int N, K;
	cin >> N >> K;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'P') {
			for (int j = i - K; j <= i + K; j++) {
				if (j >= 0 && j < N && str[j] == 'H') {
					str[j] = '-';
					ans++;
					break;
				}
			}
		}
	}

	cout << ans;

	return 0;
}