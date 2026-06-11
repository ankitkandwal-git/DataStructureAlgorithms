#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>diff(m,vector<int>(n,INT_MAX));
    pair<int,int>start={0,0};
    pair<int,int>end={m-1,n-1};
    diff[start.first][start.second]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{start.first,start.second}});
    while(!pq.empty()){
        auto x = pq.top();
        int row = x.second.first;
        int col = x.second.second;
        pq.pop();
        if(row>0){
            int delta = abs(grid[row][col]-grid[row-1][col]);
            int effort = max(diff[row][col],delta);
            if(effort<diff[row-1][col]){
                diff[row-1][col]=effort;
                pq.push({effort,{row-1,col}});
            }
        }
        if(row+1<m){
            int delta = abs(grid[row][col]-grid[row+1][col]);
            int effort = max(diff[row][col],delta);
            if(effort<diff[row+1][col]){
                diff[row+1][col]=effort;
                pq.push({effort,{row+1,col}});
            }
        }
        if(col>0){
            int delta = abs(grid[row][col]-grid[row][col-1]);
            int effort = max(diff[row][col],delta);
            if(effort<diff[row][col-1]){
                diff[row][col-1]=effort;
                pq.push({effort,{row,col-1}});
            }
        }
        if(col+1<n){
            int delta = abs(grid[row][col]-grid[row][col+1]);
            int effort = max(diff[row][col],delta);
            if(effort<diff[row][col+1]){
                diff[row][col+1]=effort;
                pq.push({effort,{row,col+1}});
            }
        }
    }
    return diff[end.first][end.second];
}
int main(){
    int m;
    cout<<"Enter the number of rows: ";
    cin>>m;
    int n;
    cout<<"Enter the number of columns: ";
    cin>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    cout<<"Enter the grid values: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int result = minimumEffortPath(grid);
    cout<<"Minimum effort required to reach the destination: "<<result<<endl;
    return 0;
}