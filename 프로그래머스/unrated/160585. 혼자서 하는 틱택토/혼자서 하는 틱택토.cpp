#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    int arr[3][3] = {0,};
    int p1=0, p2=0;
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == 'O')  p1++;
            if(board[i][j] == 'X')  p2++;
        }
    }
    if (p1 < p2) { // O보다 X개수가 많은 경우
        answer = 0;
    }
    if(p1-p2 > 1) { // O가 1개 이상 더 많은 경우
        answer = 0;
    }
    
    int win1 = 0, win2 = 0;
    for(int i=0; i<3; i++) {
        int row1 = 0, row2 = 0;
        for(int j=0; j<3; j++) {
            if(board[i][j] == 'O')  row1++;
            if(board[i][j] == 'X')  row2++;
        }
        if(row1 == 3)   win1++;
        if(row2 == 3)   win2++;
        row1 = 0; row2 = 0;
    }
    
    for(int i=0; i<3; i++) {
        int col1 = 0, col2 = 0;
        for(int j=0; j<3; j++) {
            if(board[j][i] == 'O')  col1++;
            if(board[j][i] == 'X')  col2++;
        }
        if(col1 == 3)   win1++;
        if(col2 == 3)   win2++;
        col1 = 0; col2 = 0;
    }
    
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')  win1++;
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')  win2++;
    if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')  win1++;
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')  win2++;
    
    if(win1 == win2) { // 승리가 2명인 경우
        if(win1 != 0 && win2 != 0) {
            answer = 0;
        }
    }
    if(win1 > win2) { // O가 이겼는데 O가 1개 더 많지 않은 경우
        if(p1-p2 != 1) {
            answer = 0;
        }
    }
    if(win1 < win2) {
        if(p1 != p2) { // X가 이겼는데 O와 X개수가 같지 않은 경우
            answer = 0;
        }
    }
    
    return answer;
}