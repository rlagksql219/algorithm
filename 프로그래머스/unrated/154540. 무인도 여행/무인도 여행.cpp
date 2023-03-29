#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt;
vector<int> answer;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    
    visited[x][y] = true;
    cnt += map[x][y];
    q.push({x, y});
    
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && map[nx][ny] >= 1) {
                visited[nx][ny] = true;
                cnt += map[nx][ny];
                q.push({nx, ny});
            }
        }
    }
}


vector<int> solution(vector<string> maps) {
    N = maps.size();
    M = maps[0].size();
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(maps[i][j] == 'X')   map[i][j] = 0;
            else {
                map[i][j] = maps[i][j] - '0';
            }
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] != 0 && !visited[i][j]) {
                bfs(i, j);
                answer.push_back(cnt);
                cnt = 0;
            }
        }
    }
    
    if(answer.size() == 0)  answer.push_back(-1);
    sort(answer.begin(), answer.end());
    
    return answer;
}