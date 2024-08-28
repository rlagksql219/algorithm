#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++) {
        int num = arr[i];
        while(num--) {
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}