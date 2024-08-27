#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++) {
        if(flag[i] == true) {
            int num = arr[i] * 2;
            while(num--) {
                answer.push_back(arr[i]);
            }
        }
        else {
            int num = arr[i];
            while(num--) {
                answer.pop_back();
            }
        }
    }
    
    return answer;
}