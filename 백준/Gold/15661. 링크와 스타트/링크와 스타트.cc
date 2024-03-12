#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[21][21];

int getSkillSum(vector<int> team) {
	int sum = 0;

	for (int i = 0; i < team.size(); i++) {
		for (int j = 0; j < team.size(); j++) {
			if (i == j)	continue;
			sum += arr[team[i]][team[j]];
		}
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int mindiff = 999999999;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n / 2; i++) {
		vector<int> v;
		
		for (int j = 0; j < i; j++) {
			v.push_back(0);
		}
		for (int j = 0; j < n - i; j++) {
			v.push_back(1);
		}

		do {
			vector<int> start;
			vector<int> link;

			for (int j = 0; j < n; j++) {
				if (v[j]) {
					start.push_back(j);
				}
				else {
					link.push_back(j);
				}
			}

			int diff = abs(getSkillSum(start) - getSkillSum(link));
			if (diff < mindiff) {
				mindiff = diff;
			}
		} while (next_permutation(v.begin(), v.end()));
	}

	cout << mindiff;

	return 0;
}