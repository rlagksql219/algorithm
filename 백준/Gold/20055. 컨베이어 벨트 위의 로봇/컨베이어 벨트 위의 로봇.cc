#include <iostream>
#include <deque>

using namespace std;

int n, k;
deque<int> dq;
deque<bool> check;

int cnt() {
	int num = 0;
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] == 0)	num++;
	}
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++) {
		int tmp;
		cin >> tmp;
		dq.push_back(tmp);
		check.push_back(false);
	}

	while (1) {
		ans++;

		//1.벨트 회전
		dq.push_front(dq.back());
		dq.pop_back();
		check.push_front(check.back());
		check.pop_back();

		if (check[n - 1] == true) //N번째 위치면 로봇 땅에서 내림
			check[n - 1] = false;

		//2.로봇 이동
		for (int i = n - 2; i >= 0; i--) {
			if (check[i] == true && dq[i + 1] >= 1 && check[i + 1] == false) {
				dq[i + 1]--;
				check[i] = false;
				if(i != n-2)
					check[i + 1] = true;
			}
		}

		//3.로봇 올리기
		if (dq[0] >= 1 && check[0] == false) {
			check[0] = true;
			dq[0]--;
		}

		if (cnt() >= k)	break;
	}

	cout << ans;

	return 0;
}