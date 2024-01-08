#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int M, N;
int map[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt;

int bfs(int x, int y, int value) {
    visited[x][y] = true;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if(nx >=0 && nx < M && ny >= 0 && ny < N && map[nx][ny] == value && !visited[nx][ny]) {
                visited[nx][ny] = true;
                cnt++;
                q.push({nx, ny});
            }
        }
    }
    
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    
    M = m;
    N = n;
    cnt = 0;
    int value = 0;   
    
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<picture.size(); i++) {
        for(int j=0; j<picture[0].size(); j++) {
            map[i][j] = picture[i][j];
        }
    }
    
    for(int i=0; i<picture.size(); i++) {
        for(int j=0; j<picture[0].size(); j++) {
            if(map[i][j] != 0 && !visited[i][j]) {
                number_of_area++;
                value = map[i][j];
                bfs(i, j, value);
                if(cnt > max_size_of_one_area)   max_size_of_one_area = cnt;
                cnt = 0;
                
                answer[0] = number_of_area;
                answer[1] = max_size_of_one_area;
                answer[1]++;
            }
        }
    }
                    
    return answer;
}