#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    int N = sequence.size();
    vector<long long> list1(N);
    vector<long long> list2(N);
    vector<long long> dp1(N);
    vector<long long> dp2(N);
    long long ans = 0;
    
    for(int i=0; i<sequence.size(); i++) {
        if(i%2 == 0) {
            list1[i] = sequence[i];
            list2[i] = -1 * sequence[i];
        }
        else {
            list1[i] = -1 * sequence[i];
            list2[i] = sequence[i];
        }
    }
    
    /* DP */
    dp1[0] = list1[0];
    ans = list1[0];
    if (ans < dp1[0])   ans = dp1[0];
    
    for(int i=1; i<N; i++) {
        dp1[i] = max(dp1[i-1] + list1[i], list1[i]);
        ans = max(ans, dp1[i]);
    }
    
    dp2[0] = list2[0];
    if (ans < dp2[0])   ans = dp2[0];
    for(int i=1; i<N; i++) {
        dp2[i] = max(dp2[i-1] + list2[i], list2[i]);
        ans = max(ans, dp2[i]);
    }
    
    return ans;
}