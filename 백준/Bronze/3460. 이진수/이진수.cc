#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int N;
		vector<int> v;
		cin >> N;

		while (N) {
			v.push_back(N % 2);
			N /= 2;
		}
		
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1)	cout << i << " ";
		}
	}

	return 0;
}