#include <iostream>
#include <vector>

using namespace std;

/*
https://velog.io/@rlagksql219/BOJC-11726-2n-%ED%83%80%EC%9D%BC%EB%A7%81-DP
*/

int main() {
	int N;
	vector<int> v;

	cin >> N;
	v.push_back(0); //0을 나타내는 경우의 수
	v.push_back(1); //1을 나타내는 경우의 수
	v.push_back(2); //2를 나타내는 경우의 수

	for (int i = 3; i <= N; i++) {
		int tmp;

		tmp = (v[i - 1] + v[i - 2]) % 10007;
		v.push_back(tmp);
	}

	cout << v[N] << endl;

	return 0;
}
