#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> ans;
    vector<int> x;
    vector<int> y;
    int x_min=0, y_min=0, x_max=0, y_max=0;
    
    for(int i=0; i<wallpaper.size(); i++) {
        for(int j=0; j<wallpaper[0].size(); j++) {
            if(wallpaper[i][j] == '#') {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    
    x_min = *min_element(x.begin(), x.end());
    x_max = *max_element(x.begin(), x.end());
    y_min = *min_element(y.begin(), y.end());
    y_max = *max_element(y.begin(), y.end());
    x_max++;
    y_max++;
    
    ans.push_back(x_min);
    ans.push_back(y_min);
    ans.push_back(x_max);
    ans.push_back(y_max);
    
    return ans;
}