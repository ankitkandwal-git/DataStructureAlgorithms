#include<bits/stdc++.h>
using namespace std;
int uniquePathsII(int m, int n, vector<vector<int>>& grid){
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (grid[i][j] == -1){
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else{
                int right = 0;
                int down = 0;
                if (j > 0){
                    right = dp[i][j - 1];
                }
                if (i > 0){
                    down = dp[i - 1][j];
                }
                dp[i][j] = down + right;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i< m; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    }
    cout << uniquePathsII(m, n, grid);
    return 0;
}