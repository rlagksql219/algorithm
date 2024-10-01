#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    string even, odd;
    
    for(int i=0; i<num_list.size(); i++) {
        if(num_list[i] % 2 == 0) {
            even += num_list[i] + '0';
        }
        else {
            odd += num_list[i] + '0';
        }
    }
    
    answer = stoi(even) + stoi(odd);
    
    return answer;
}