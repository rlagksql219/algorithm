#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = 0, p = 0;
    
    for(int i=n-1; i>=0; i--) {
        int cnt = 0; //트럭 왔다갔다 이동 횟수
        d -= deliveries[i];
        p -= pickups[i];
        
        while(d < 0 || p < 0) {
            d += cap; //전달 할 물건 존재했기에 cap만큼의 배달량을 처리 할 수 있음
            p += cap; //회수 할 물건 존재했기에 cap만큼의 회수량을 처리 할 수 있음
            cnt += 1; //해당 장소에 한 번 방문한 것으로 커버되지 않으면, 다시 방문해서 cap만큼의 배달량, 회수량 즐가시킴
        }
        
        answer += (i+1) * 2 * cnt; //여기서 cnt 곱해줘야 함!
    }

    return answer;
}