#include <string>
#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

int N, M;
int map[100][100];
int visited[100][100];
int cnt[100][100];
int start_x, start_y, middle_x, middle_y, exit_x, exit_y;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void bfs(int x, int y, int target_x, int target_y) {
    if(x == target_x && y == target_y)
        return;
    
    visited[x][y] = true;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        
        q.pop();
        
        if(xx == target_x && yy == target_y)
            break;
        
        for(int i=0; i<4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt[nx][ny] = cnt[xx][yy] + 1;
            }
        }
    }
}


int solution(vector<string> maps) {
    int answer = 0;
    int dist1 = 0; int dist2 = 0;
    
    N = maps.size();
    M = maps[0].size();
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(maps[i][j] == 'O') {
                map[i][j] = 0;
            }
            else if(maps[i][j] == 'X') {
                map[i][j] = 1;
            }
            else if(maps[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
            else if(maps[i][j] == 'L') {
                middle_x = i;
                middle_y = j;
            }
            else {
                exit_x = i;
                exit_y = j;
            }
        }
    }
        
    bfs(start_x, start_y, middle_x, middle_y);
    dist1 = cnt[middle_x][middle_y];
    
    memset(visited, 0, sizeof(visited));
    memset(cnt, 0, sizeof(cnt));
    
    bfs(middle_x, middle_y, exit_x, exit_y);
    dist2 = cnt[exit_x][exit_y];
        
    if(dist1 == 0 || dist2 == 0)
        answer = -1;
    else {
        answer = dist1 + dist2;
    }
    
    
    return answer;
}
