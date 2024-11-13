#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> term;
    
    for(int i=0; i<progresses.size(); i++) {
        int num = progresses[i];
        int d = speeds[i];
        int x = (100 - num) / d;
        if((100 - num) % d != 0)    x++;
        term.push(x);
    }
    
    while(!term.empty()) {
        int day = term.front();
        term.pop();
        int cnt = 1;
        
        while(!term.empty() && term.front() <= day) {
            term.pop();
            cnt++;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}