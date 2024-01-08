#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int numer = 0, denom = 0;
    
    denom = denom1 * denom2;
    numer = numer1 * denom2 + numer2 * denom1;
    for(int i=2; i<=1000; i++) {
        if(denom % i == 0 && numer % i ==0) {
            denom /= i;
            numer /= i;
        }
    }
    
    for(int i=2; i<=1000; i++) {
        if(denom % i == 0 && numer % i ==0) {
            denom /= i;
            numer /= i;
        }
    }
    
    answer.push_back(numer);
    answer.push_back(denom);
    
    return answer;
}