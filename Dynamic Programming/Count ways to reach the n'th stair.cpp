// https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1#

int countWays(int n)
    {
       long long int m = 1000000007;
       int dp[n+1];
       dp[0] = 1;
       dp[1] = 1;
       for(int i=2;i<=n;i++){
           dp[i] = ((dp[i-1])%m + (dp[i-2])%m)%m;
       }
       return dp[n]%m;
    }
