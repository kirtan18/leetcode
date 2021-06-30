// https://leetcode.com/problems/longest-palindromic-subsequence/


  class Solution {
    int helper(string s,string x){
         int m = s.size();
         int n = x.size();

         int dp[m+1][n+1];
     
         for(int i = 0 ; i <= m ; i++){
             for(int j = 0 ; j <= n ; j++){
                 if(i == 0 || j == 0)dp[i][j] = 0;
            
                 else if(s[i-1] == x[j-1]){
                     dp[i][j] = 1 + dp[i-1][j-1];
                  }

                 else{
                     dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                   }

             }
          }

     return dp[m][n];
    }
    
public:
    int longestPalindromeSubseq(string s) {      
          string t = s;
          reverse(s.begin(), s.end());
         return helper(t,s);
        
    }
};
