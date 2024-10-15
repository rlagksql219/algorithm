#include <iostream>
#include <vector>

using namespace std;

int N, L;
int map[101][101];
int ans;

bool check_row(int row) {
	vector<bool> used(N, false); //경사로가 설치된 칸 기록

	for (int i = 0; i < N - 1; i++) {
		int cur = map[row][i];
		int next = map[row][i+1];

		if (cur == next)	continue; //높이가 같은 경우
		else if (cur + 1 == next) { //높이가 1 증가
			for (int j = 0; j < L; j++) {
				if (i - j < 0 || map[row][i-j] != cur || used[i - j])	return false;
				used[i - j] = true;
			}
		}
		else if (cur - 1 == next) { //높이가 1 감소
			for (int j = 1; j <= L; j++) {
				if (i + j > N || map[row][i+j] != next || used[i + j])	return false;
				used[i + j] = true;
			}
			i += L - 1;
		}
		else {
			return false;
		}
	}
	return true;
}

bool check_col(int col) {
	vector<bool> used(N, false); //경사로가 설치된 칸 기록

	for (int i = 0; i < N - 1; i++) {
		int cur = map[i][col];
		int next = map[i + 1][col];

		if (cur == next)	continue; //높이가 같은 경우
		else if (cur + 1 == next) { //높이가 1 증가
			for (int j = 0; j < L; j++) {
				if (i - j < 0 || map[i - j][col] != cur || used[i - j])	return false;
				used[i - j] = true;
			}
		}
		else if (cur - 1 == next) { //높이가 1 감소
			for (int j = 1; j <= L; j++) {
				if (i + j > N || map[i + j][col] != next || used[i + j])	return false;
				used[i + j] = true;
			}
			i += L - 1;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		if (check_row(i))	ans++;
		if (check_col(i))	ans++;
	}

	cout << ans;

	return 0;
}