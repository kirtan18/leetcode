// https://practice.geeksforgeeks.org/problems/coin-change2448/1#

//  This method in we use knapsack unbounded method bcs in this question in value use over 1 times so 

 long long int count( int S[], int m, int n )
    {
      long long int dp[m+1][n+1];
      
      for(int i = 1 ; i <= n ; i++){
          dp[0][i] = 0;
      }
      for(int j = 1 ; j <= m ; j++){
          dp[j][0] = 1;
      }
      
      for(int i = 1 ; i <= m ; i++){
          for(int j = 1 ; j <= n ; j++){
              if(S[i-1] > j){
                  dp[i][j] = dp[i-1][j];
              }
              else{
                  dp[i][j] = dp[i][j - S[i-1]] + dp[i-1][j];
              }
          }
      }
      
      return dp[m][n];
    }
   

/////////////////////////////////////////////   Recursive Approch ////////////////////////////////////////


 int count( int S[], int m, int n )
{
  
    if (n == 0)
        return 1;
     
    if (n < 0)
        return 0;

    if (m <=0 && n >= 1)
        return 0;

    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}


