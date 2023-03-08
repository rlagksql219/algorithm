#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    vector<int> mark;
    
    for(int i=0; i<goal.size(); i++) {
        if(goal[i] == cards1[0]) {
            cards1.erase(cards1.begin());
            mark.push_back(1);
            continue;
        }
        
        if(goal[i] == cards2[0]) {
            cards2.erase(cards2.begin());
            mark.push_back(1);
            continue;
        }
    }
    
    if(mark.size() != goal.size())
        answer = "No";
    else
        answer = "Yes";
    
    
    return answer;
}
