#include <iostream>
#include <vector>

using namespace std;

/*
https://velog.io/@rlagksql219/BOJC-9095-1-2-3-%EB%8D%94%ED%95%98%EA%B8%B0-DP
*/

int main() {
	int T;

	cin >> T;
	while (T--) {
		int N;
		vector<int> v;

		cin >> N;
		v.push_back(0); //0을 나타내는 경우의 수
		v.push_back(1); //1을 나타내는 경우의 수
		v.push_back(2); //2를 나타내는 경우의 수
		v.push_back(4); //3을 나타내는 경우의 수

		for (int i = 4; i <= N; i++) {
			int tmp;

			tmp = v[i - 1] + v[i - 2] + v[i - 3];
			v.push_back(tmp);
		}

		cout << v[N] << endl;
	}


	return 0;
}