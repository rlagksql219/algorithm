#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<pair<int, int>> v;
    
    for(int i=0; i<emergency.size(); i++) {
        v.push_back({emergency[i], i});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<emergency.size(); i++) {
        answer.push_back(emergency.size() - v[i].second);
    }
    
    return answer;
}