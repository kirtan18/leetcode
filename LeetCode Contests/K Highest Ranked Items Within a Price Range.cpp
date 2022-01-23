// https://leetcode.com/contest/biweekly-contest-70/problems/k-highest-ranked-items-within-a-price-range/

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pr , vector<int>& s, int k) {
       
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.emplace(s[0],s[1]);
        
        vector<pair<int,int>>dir = {{-1,0},{0,1},{0,-1},{1,0}};
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        dp[s[0]][s[1]] = 0;
        
        vector<tuple<int,int,int,int>>res;
        
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                auto [dx,dy] = dir[i];
                
                int x = r + dx ;
                int y = c + dy;
                
                if(x>=0 && y>=0 && x<n && y<m && dp[x][y] == -1 && grid[x][y]){
                    q.emplace(x,y);
                    dp[x][y] = 1 + dp[r][c];
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j] > -1 && (grid[i][j] >= pr[0] && grid[i][j] <= pr[1])){
                    res.push_back({dp[i][j], grid[i][j],i,j});
                }
            }
        }
        
        sort(res.begin(),res.end());
        
        vector<vector<int>>ans;
        
        for(auto it : res){
            auto [dis,price,i,j] = it;
            ans.push_back({i,j});
            k--;
            if(k == 0)break;
        }
        
        return ans;
    }
};
