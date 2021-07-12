https://leetcode.com/contest/biweekly-contest-56/problems/nearest-exit-from-entrance-in-maze/


class Solution {
public:
    int n , m;
    int vis[105][105];
    
    bool isValid(int x ,int y , vector<vector<char>>& maze){
        return (x>=0 && x < n && y >= 0 && y < m && vis[x][y] == false && maze[x][y] == '.');
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        n = maze.size();
        m =  maze[0].size();
        
        memset(vis,false,sizeof vis);
        
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vis[entrance[0]][entrance[1]] = true;
        
        queue<vector<int>>q;
        q.push({entrance[0],entrance[1],0});
        
        while(q.size() > 0){
            auto f = q.front();
            q.pop();
            
            if(f[0] == 0 || f[0] == n-1 || f[1] == 0 || f[1] == m-1){
                if(f[0] == entrance[0] && f[1] == entrance[1]){
                    
                }
                else{
                    return f[2];
                }
            }
            
            for(auto i : dir){
                int new_x = f[0] + i[0];
                int new_y = f[1] + i[1];
                
                if(isValid(new_x,new_y,maze) == true){
                    vis[new_x][new_y] = true;
                    q.push({new_x,new_y,f[2]+1});
                } 
            }       
        }       
        return -1;
    }
};
