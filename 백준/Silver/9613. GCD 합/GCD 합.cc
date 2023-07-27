#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	int T;

	cin >> T;
	while (T--) {
		int n;
		vector<int> v;
		long long sum = 0;

		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;

			cin >> tmp;
			v.push_back(tmp);
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(v[i], v[j]);
			}
		}

		cout << sum << '\n';
	}

	return 0;
}