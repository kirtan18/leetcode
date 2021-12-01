// https://leetcode.com/problems/unique-paths/

///////////////////////////////////////////// TLE ////////////////////////////////////////

class Solution {
    
    int solve(int i,int j,int m,int n){
        if(i>=m || j>=n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        return solve(i+1,j,m,n)+solve(i,j+1,m,n);
    }
public:
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};

////////////////////////////////////// Avoid TLE ///////////////////////////////////////
class Solution {
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i>=m || j>= n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = solve(i+1,j,m,n,dp) + solve(i,j+1,m,n,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};


/////////////////////////////// Optimal Approch /////////////////////////////////

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
