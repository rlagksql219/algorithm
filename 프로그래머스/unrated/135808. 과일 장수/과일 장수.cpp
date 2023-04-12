#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(int a, int b) {
    return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), compare);
    for(int i=0; i<score.size(); i++) {
        if((i+1) % m == 0)
            answer += score[i] * m;
    }
    
    return answer;
}