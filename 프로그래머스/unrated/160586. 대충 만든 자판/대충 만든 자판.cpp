#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i=0; i<targets.size(); i++) {
        answer.push_back(0);
        for(int j=0; j<targets[i].size(); j++) {
            char c = targets[i][j];
            int flag = 0, num = 101; //keymap 최대 길이가 100이므로 101로 초기화 후, 최솟값 찾기
            
            for(int k=0; k<keymap.size(); k++) {
                for(int l=0; l<keymap[k].size(); l++) {
                    if(keymap[k][l] == c) {
                        num = min(num, l+1);
                        flag = 1;
                        break;
                    }
                }
            }
            
            if(flag == 0) { //타이핑 불가능한 경우
                answer[i] = -1;
                break;
            }
            answer[i] += num;
        }
    }
    
    return answer;
}