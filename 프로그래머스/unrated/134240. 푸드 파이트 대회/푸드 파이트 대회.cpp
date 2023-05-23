#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for(int i=1; i<food.size(); i++) {
        int index = food[i] / 2;
        for(int j=0; j<index; j++)
            answer += i + '0';
    }
    
    string tmp = answer;
    answer += '0';
    
    for(int i=tmp.size()-1; i>=0; i--) {
        answer += tmp[i];
    }
      
    return answer;
}