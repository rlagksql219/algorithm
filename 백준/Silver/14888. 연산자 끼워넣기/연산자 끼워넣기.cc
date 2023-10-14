#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[250];
int tmp_arr[250];
vector<int> c;

int calculate(int n1, int c, int n2) {
	
	if (c == 11)
		return n1 + n2;
	else if (c == 22)
		return n1 - n2;
	else if (c == 33)
		return n1 * n2;
	else
		return n1 / n2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c1, c2, c3, c4;
	int max = -1000000001;
	int min = 1000000001;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		int index = i*2;
		
		cin >> tmp;
		arr[index] = tmp;
	}

	cin >> c1 >> c2 >> c3 >> c4;
	while (c1--)
		c.push_back(11);
	while (c2--)
		c.push_back(22);
	while (c3--)
		c.push_back(33);
	while (c4--)
		c.push_back(44);


	sort(c.begin(), c.end());
	do {
		for (int i = 0; i < c.size(); i++) {
			int index = i * 2 + 1;
			arr[index] = c[i];
		}
		memcpy(tmp_arr, arr, sizeof(arr));
		
		int size = n + c.size() + 1;
		for (int i = 0; i < size - 2; i++) {
			tmp_arr[i+2] = calculate(tmp_arr[i], tmp_arr[i + 1], tmp_arr[i + 2]);
			i++;
		}
		int ans = tmp_arr[size - 2];
		if (max < ans)
			max = ans;
		if (min > ans)
			min = ans;

		memcpy(tmp_arr, arr, sizeof(arr));
	} while (next_permutation(c.begin(), c.end()));

	cout << max << '\n';
	cout << min << '\n';

	return 0;
}