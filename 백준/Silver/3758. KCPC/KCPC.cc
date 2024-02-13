#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 
int tc, n, k, t, m, a, b, c;
int d[101][101], tim[101], cnt[101];
 
int main() {
    scanf("%d", &tc);
    while (tc--) {
        memset(d, 0, sizeof(d));
        memset(tim, 0, sizeof(tim));
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%d%d%d", &n, &k, &t, &m);
        t--;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            a--; b--;
            d[a][b] = max(d[a][b], c);
            cnt[a]++;
            tim[a] = i;
        }
        vector < pair<int, pair<int, pair<int, int>>>> v;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < k; j++) 
                sum += d[i][j];
            v.push_back({ sum,{-cnt[i],{-tim[i],i}} });
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (v[i].second.second.second == t) printf("%d\n", n - i);
        }
    }
 
    return 0;
}
