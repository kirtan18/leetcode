https://leetcode.com/problems/unique-paths-iii/

class Solution {
    
    void dfs(vector<vector<int>>& grid,int i,int j,int cnt,int &empty,int &res){
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == -1 )return;
        
        if(grid[i][j] == 2){
            if(empty == cnt)res++;
            return;
        }
        
        grid[i][j] = -1;
        
        dfs(grid,i+1,j,cnt+1,empty,res);
        dfs(grid,i-1,j,cnt+1,empty,res);
        dfs(grid,i,j+1,cnt+1,empty,res);
        dfs(grid,i,j-1,cnt+1,empty,res);
        
        grid[i][j] = 0;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x = 0 , start_y = 0;
        int empty = 1;
        int res = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
                else if(grid[i][j] == 0){
                    empty++;
                }
            }
        }
        
        dfs(grid,start_x,start_y,0,empty,res);
        return res;
    }
};
