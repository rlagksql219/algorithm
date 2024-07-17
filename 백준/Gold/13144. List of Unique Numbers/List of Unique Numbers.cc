#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>
#include <map>

using namespace std;

int arr[100001];
bool visited[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int end = 0;
	long res = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int st = 0; st < N; st++)
	{
		while (end < N)
		{
			if (visited[arr[end]]) break;

			visited[arr[end++]] = true;
		}

		res += end - st;
		visited[arr[st]] = false;
	}

	cout << res;
}