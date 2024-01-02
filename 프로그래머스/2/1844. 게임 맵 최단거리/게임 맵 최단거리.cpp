#include <vector>
#include <queue>

using namespace std;

int answer = 0;
int X, Y;
int map[101][101];
int cnt[101][101];
bool visited[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y) {
    visited[x][y] = true;
    cnt[x][y]++;
    
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        
        q.pop();
        
        for(int i=0; i<4; i++) {
            int xx = nx + dx[i];
            int yy = ny + dy[i];
            
            if(xx >= 0 && xx <= Y && yy >= 0 && yy <= X && map[xx][yy] == 1 && !visited[xx][yy]) {
                q.push({xx, yy});
                visited[xx][yy] = true;
                cnt[xx][yy] = cnt[nx][ny] + 1;
            }
        }
    }
}

int solution(vector<vector<int> > maps) {
    X = maps[0].size();
    Y = maps.size();
    
    for(int i=0; i<maps.size(); i++) {
        for(int j=0; j<maps[0].size(); j++) {
            map[i][j] = maps[i][j];
        }
    }
    
    bfs(0, 0);
    
    if(cnt[Y-1][X-1] == 0) {
        return -1;
    }
    else {
        return cnt[Y-1][X-1];
    }
}