#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;
	while (N--) {
		int n;
		int student[20];
		int ans = 0;

		cin >> n;
		for (int i = 0; i < 20; i++) {
			cin >> student[i];
		}
		for (int i = 0; i < 20; i++) {
			for (int j = i; j < 20; j++) {
				if (student[i] > student[j])	ans++;
			}
		}

		cout << n << " " << ans << '\n';
	}

	return 0;
}