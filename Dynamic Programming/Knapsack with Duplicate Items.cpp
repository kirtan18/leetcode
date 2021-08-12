https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

int knapSack(int N, int W, int val[], int wt[])
    {
         int dp[W+1];
         memset(dp, 0, sizeof dp);

     for (int i=0; i<=W; i++)
       for (int j=0; j<N; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
     return dp[W];
    }
