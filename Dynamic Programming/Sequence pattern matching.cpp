// https://leetcode.com/problems/is-subsequence/

///////////////////////////////////    Brute force || T.C = O(m*n) || S.C = O(n)     ////////////////////////////////////////////////////////////

 class Solution {
    
    int helper(string s,string t){
        int m = s.size();
        int n = t.size();
        
        int dp[m+1][n+1];
        
        for(int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n ; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s[i-1] == t[j-1]){
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
    bool isSubsequence(string s, string t) {
       
        int ans = helper(s,t);
        
        if(ans == s.length()){
            return true;
        }
        return false;
        
    }
};


///////////////////////////////////////   Optimal using two pointer  ,  T.C = O(m+n) || S.C = O(1)  ///////////////////////////////////


  bool isSubsequence(string s, string t) {
        int i = 0 , j = 0;
        
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }  
        return i == s.size();        
    }


















