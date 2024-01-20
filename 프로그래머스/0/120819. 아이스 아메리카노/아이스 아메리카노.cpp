#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    int cnt = 0;
    
    while(money >= 5500) {
        money -= 5500;
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(money);
    
    return answer;
}