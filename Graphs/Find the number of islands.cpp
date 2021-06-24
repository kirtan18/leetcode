

class Solution
{
    void dfs(int i , int j , int vis[][501] ,vector<vector<char>> &grid ,int n,int m){
        if(i<0 || j < 0 || i >= n || j >= m)return;
        if(grid[i][j] == 0)return;
        if(!vis[i][j]){
            vis[i][j] = 1;
            dfs(i+1,j,vis,grid,n,m);
            dfs(i-1,j,vis,grid,n,m);
            dfs(i,j+1,vis,grid,n,m);
            dfs(i,j-1,vis,grid,n,m);
            dfs(i+1,j+1,vis,grid,n,m);
            dfs(i-1,j-1,vis,grid,n,m);
            dfs(i+1,j-1,vis,grid,n,m);
            dfs(i-1,j+1,vis,grid,n,m);
        }
    }
     
    public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int vis[501][501];
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                vis[i][j] = 0;
            }
        }
        
        int c = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i,j,vis,grid,n,m);
                    c++;
                }
            }
        }
        return c;
    }
};
