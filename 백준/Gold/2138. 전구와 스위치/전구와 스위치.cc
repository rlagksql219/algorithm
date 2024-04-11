#include <iostream>
#include <string.h>
#include <cmath>
#define MAX 987654321

using namespace std;

int N;
string st, dt;
int ans = MAX;

void solve(int mark) {
	string tmp = st;
	int cnt = 0;
	if (mark == 0) { //0번 스위치 뒤집고 시작
		tmp[0] = (tmp[0] == '0') ? '1' : '0';
		tmp[1] = (tmp[1] == '0') ? '1' : '0';
		cnt++;
	}
	for (int i = 1; i < N; i++) {
		if (tmp[i - 1] != dt[i - 1]) {
			if (i - 1 >= 0) //(i-1) 스위치 변경
				tmp[i - 1] = (tmp[i - 1] == '0') ? '1' : '0';
			tmp[i] = (tmp[i] == '0') ? '1' : '0'; //i 스위치 변경
			if (i + 1 <= N - 1) //(i+1) 스위치 변경
				tmp[i + 1] = (tmp[i + 1] == '0') ? '1' : '0';

			cnt++;
		}
	}
	if (tmp == dt)
		ans = min(ans, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> st >> dt;
	solve(0);
	solve(1);
	if (ans != MAX)
		cout << ans;
	else {
		cout << -1;
	}

	return 0;
}