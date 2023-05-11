#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, k;
	vector<int> v;
	vector<int> answer;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	do {
		string str;
		for (int i = 0; i < k; i++) {
			if (v[i] < 10)
				str += v[i] + '0';
			else
				str += to_string(v[i]);
		}

		if (find(answer.begin(), answer.end(), stoi(str)) == answer.end())
			answer.push_back(stoi(str));
		reverse(v.begin() + k, v.end());
	} while (next_permutation(v.begin(), v.end()));

	cout << answer.size();

	return 0;
}