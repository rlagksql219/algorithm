#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> list;
    
    for(int i=0; i<k; i++) {
        if(i >= score.size())   break; //반례 : score 크기보다 k가 더 큰 경우, answer 배열의 크기가 정답보다 커짐
        list.push_back(score[i]);
        int min = *min_element(list.begin(), list.end());
        answer.push_back(min);
    }
    
    for(int i=k; i<score.size(); i++) {
        list.push_back(score[i]);
        sort(list.begin(), list.end());
        list.erase(list.begin());
        
        int min = *min_element(list.begin(), list.end());
        answer.push_back(min);
    }
    
    return answer;
}