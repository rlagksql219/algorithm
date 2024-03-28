#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for(int i=0; i<my_string.length(); i++) {
        if((int)my_string[i] >= 48 && (int)my_string[i] <= 57) {
            int num = (int)my_string[i] - 48;
            answer.push_back(num);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}