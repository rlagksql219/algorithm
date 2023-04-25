#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int cnt[1001] = {0,};
    
    for(int i=0; i<array.size(); i++)
        cnt[array[i]]++;
    
    int max1 = *max_element(cnt, cnt+1001);
    int index = max_element(cnt, cnt+1001) - cnt;
    cnt[index]--;
    answer = index;
    
    int max2 = *max_element(cnt, cnt+1001);
    if(max1 == max2)
        answer = -1;
    
    return answer;
}