#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>&grid,pair<int,int>start,pair<int,int>end){
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{start.first,start.second}});
    vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
    dist[start.first][start.second] = 0;
    while(!q.empty()){
        auto x = q.front();
        int d = x.first;
        int row = x.second.first;
        int col = x.second.second;
        q.pop();
        if(row == end.first && col == end.second){
            return d;
        }
        if(row>0 && grid[row-1][col]==1){
            if(dist[row][col]+1 < dist[row-1][col]){
                dist[row-1][col]=dist[row][col]+1;
                q.push({dist[row-1][col],{row-1,col}});
            }
        }
        if(row+1<m && grid[row+1][col]==1){
            if(dist[row][col]+1<dist[row+1][col]){
                dist[row+1][col]=dist[row][col]+1;
                q.push({dist[row+1][col],{row+1,col}});
            }
        }
        if(col>0 && grid[row][col-1]==1){
            if(dist[row][col]+1 < dist[row][col-1]){
                dist[row][col-1]=dist[row][col]+1;
                q.push({dist[row][col-1],{row,col-1}});
            }
        }
        if(col+1<n && grid[row][col+1]==1){
            if(dist[row][col]+1 < dist[row][col+1]){
                dist[row][col+1]=dist[row][col]+1;
                q.push({dist[row][col+1],{row,col+1}});
            }
        }
    }
    return -1;
}
int main(){
    int m;
    cout<<"Enter the number of rows: ";
    cin>>m;
    int n;
    cout<<"Enter the number of columns: ";
    cin>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    cout<<"Enter the grid: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int startRow,startCol,endRow,endCol;
    cout<<"Enter the starting point (row and column): ";
    cin>>startRow>>startCol;
    cout<<"Enter the ending point (row and column): ";
    cin>>endRow>>endCol;
    int result = shortestPath(grid,{startRow,startCol},{endRow,endCol});
    if(result==-1){
        cout<<"No path exists from the starting point to the ending point."<<endl;
    }
    else{
        cout<<"The shortest path from the starting point to the ending point is: "<<result<<endl;
    }
    return 0;

}