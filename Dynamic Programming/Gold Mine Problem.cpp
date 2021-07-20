https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1#

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> adj)
    {
        for(int col = m-2 ; col >= 0 ; col--){
            
            for(int row = 0 ; row < n ; row++){
                
                int right = adj[row][col+1];
                
                int right_up = (row == 0) ? 0 : adj[row-1][col+1];
                
                int right_down = (row == n-1) ? 0 : adj[row+1][col+1];
                
                adj[row][col] = adj[row][col] + max( right , max(right_up , right_down));
            }
            
        }
        
        int res = adj[0][0];
        for(int i = 1 ; i < n ; i++){
            res = max(res,adj[i][0]);
        }
        return res;
        
    }
};
