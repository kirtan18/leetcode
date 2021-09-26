https://leetcode.com/contest/weekly-contest-260/problems/grid-game/

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long ans = 1e18;
        long *upper = new long[n+2]();
        long *lower = new long[n+2]();    
        
        for(int i = n ; i >= 1 ; i--){
            upper[i] = upper[i+1] + grid[0][i-1]; 
        }
        
        for(int i = 1 ; i <= n ; i++){
            lower[i] = lower[i-1] + grid[1][i-1];
        }
        
        for(int i = 1 ; i <= n ; i++){
            ans = min(max(upper[i+1] , lower[i-1]),ans);
        }
        return ans;
    }
};
