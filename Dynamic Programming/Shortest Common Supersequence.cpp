// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#


 /////////////////////////////////////////////////   Top - Down  /////////////////////////////////////////////////////////////

   int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
       int dp[m+1][n+1];
       
       for(int i = 0 ; i <=  m ; i++){
           for(int j = 0 ; j <= n ; j++){
               if(i == 0 || j == 0){
                   dp[i][j] = 0;
               }
               
               else if(X[i-1] == Y[j-1]){
                   dp[i][j] = 1 + dp[i-1][j-1];
               }
               else{
                   dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
               }
           }
       }
       
       int ans = m + n - dp[m][n];
       
       return ans;
       
    }


////////////////////////////////////////////////  Recursion (TLE)  //////////////////////////////////////////////

  int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        if(m==0)return n;
        if(n==0)return m;
        
        if(X[m-1] == Y[n-1]){
            return 1 + shortestCommonSupersequence(X,Y,m-1,n-1);
        }
        
        return 1 + min(shortestCommonSupersequence(X,Y,m-1,n),
                       (shortestCommonSupersequence(X,Y,m,n-1)));
        
    }


 
