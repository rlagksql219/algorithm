#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++) {
        int length = arr.size();
        if(length % 2 == 0) {
            if(i % 2 != 0)  arr[i] += n;
        }
        else {
            if(i % 2 == 0)  arr[i] += n;
        }
        
        answer.push_back(arr[i]);
    }
    
    return answer;
}