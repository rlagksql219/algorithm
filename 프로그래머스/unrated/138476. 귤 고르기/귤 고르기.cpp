#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
} 

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    
    for(int i=0; i<tangerine.size(); i++) {
        m[tangerine[i]] += 1;
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<k; i++) {
        int max = v[0].second;
        int max_index = v[0].first;
        v.erase(v.begin());
        answer++;
        i += max-1;
    }
    
    return answer;
}