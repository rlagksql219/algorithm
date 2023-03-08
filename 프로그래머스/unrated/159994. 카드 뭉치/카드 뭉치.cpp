#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    vector<int> mark;
    
    for(int i=0; i<goal.size(); i++) {
        /*for(int j=0; j<cards1.size(); j++) {
            if(goal[i] == cards1[j]) {
                cards1.erase(cards1.begin());
                mark.push_back(1);
                break;
            }
        }*/
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
        
        /*for(int j=0; j<cards2.size(); j++) {
            if(goal[i] == cards2[j]) {
                cards2.erase(cards2.begin());
                mark.push_back(1);
                break;
            }
        }*/
    }
    
    if(mark.size() != goal.size())
        answer = "No";
    else
        answer = "Yes";
    
    return answer;
}