#include <queue>
#include <vector>

using namespace std;

int visited[1000001];

int bfs(int node, int target, int d) {
    queue<pair<int, int>> q;
    q.push({node, 0});
    
    while(!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(x == target) {
            return cnt;
            break;
        }
        
        if(x*2 >= 0 && x*2 < 1000001 && !visited[x*2]) {
            visited[x*2] = true;
            q.push({x*2, cnt+1});
        }
        if(x*2 >= 0 && x*3 < 1000001 && !visited[x*3]) {
            visited[x*3] = true;
            q.push({x*3, cnt+1});
        }
        if(x+d >= 0 && x+d < 1000001 && !visited[x+d]) {
            visited[x+d] = true;
            q.push({x+d, cnt+1});
        }
    }
    
    return -1;
}


int solution(int x, int y, int n) {
    int answer = 0;
    
    visited[x] = true;
    answer = bfs(x, y, n);
    
    return answer;
}