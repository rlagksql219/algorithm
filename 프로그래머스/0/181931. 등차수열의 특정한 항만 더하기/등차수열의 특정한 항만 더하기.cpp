#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    int sum = a;
    
    for(int i=0; i<included.size(); i++) {
        if(i == 0) {
            if(included[i]) answer += sum;
        }
        else {
            sum += d;
            if(included[i]) answer += sum;
        }
    }
    
    return answer;
}