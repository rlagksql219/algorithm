#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    long long answer = -100000000000000;
    
    for(int i=0; i<numbers.size(); i++) {
        for(int j=i; j<numbers.size(); j++) {
            if(i == j)  continue;
            if(answer < numbers[i]*numbers[j]) {
                answer = numbers[i]*numbers[j];
            }
        }
    }
    
    return answer;
}