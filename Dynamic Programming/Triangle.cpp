// https://leetcode.com/problems/triangle/

////////////////////////////////////////////// Memoization || T.C=  O(2^N) ///////////////////////////////////////////////////////

class Solution {
    int solve(int i,int j,int n,vector<vector<int>>&dp,vector<vector<int>>&mat){
        if(i == n-1){
            return mat[i][j];
        }
        if(dp[i][j] != -1)return dp[i][j];
        int d = mat[i][j] + solve(i+1,j,n,dp,mat);
        int dr = mat[i][j] + solve(i+1,j+1,n,dp,mat);
        
        return dp[i][j] = min(d,dr);
    }
    
public:
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int> > dp(n,vector<int>(n,-1));
        return solve(0,0,n,dp,mat);
    }
};


/////////////////////////////////////////  Tabulation || T.C = O(N*N)  ////////////////////////////////////////////////////////
class Solution {
public:
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            dp[n-1][i] = mat[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = mat[i][j] + dp[i+1][j];
                int dr = mat[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dr);
            }
        }
        return dp[0][0];
    }
};

////////////////////////////////////////////// Space Optimization || T.C = O(N*N) /////////////////////////////////////////////////
class Solution {
public:
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = mat[i][j] + mat[i+1][j];
                int dr = mat[i][j] + mat[i+1][j+1];
                mat[i][j] = min(d,dr);
            }
        }
        return mat[0][0];
    }
};
