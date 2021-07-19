https://practice.geeksforgeeks.org/problems/edit-distance3702/1#

class Solution {
    
    int solve(string s1 , string s2 , int n , int m ,vector<vector<int>> &dp){
        
        if(n == 0)return m;
        if(m == 0)return n;
        
        if(dp[n][m] != -1)return dp[n][m];
        
        if(s1[n-1] == s2[m-1]){
            if(dp[n-1][m-1] == -1){
                return dp[n][m] = solve(s1,s2,n-1,m-1,dp);
            }
            else{
                dp[n][m] = dp[n-1][m-1];
            }
        }
        
        else{
            int m1,m2,m3;
            
            if(dp[n-1][m] != -1){
                m1 = dp[n-1][m];
            }
            else{
                m1 = solve(s1,s2,n-1,m,dp);
            }
            
            if(dp[n][m-1] != -1){
                m2 = dp[n][m-1];
            }
            else{
                m2 = solve(s1,s2,n,m-1,dp);
            }
            
            if(dp[n-1][m-1] != -1){
                m3 = dp[n-1][m-1];
            }
            else{
                m3 = solve(s1,s2,n-1,m-1,dp);
            }
            return dp[n][m] = 1 + min (m1,min(m2,m3));
        }
        
        return dp[n][m];
    }
    
    
  public:
    int editDistance(string s, string t){
        int n = s.size();
        int m = t.size();
         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
         return solve(s,t,n,m,dp);
    }
};
