https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1#

////////////////////////////////////////////////////////  Brute || T.c = O(N^2) TLE || S.C = O(N) ////////////////////////////////////////////////////////

int longestSubsequence(int n, int a[])
    {
       int dp[n];
       
       for(int i = 0 ; i < n ; i++)dp[i] = 1;
       
       for(int i = 1 ; i < n ; i++){
           for(int j = 0 ; j < i ; j++){
               if(a[j] < a[i]){
                   dp[i] = max(dp[i], dp[j] + 1);
               }
           }
       }
       
       int maxi = INT_MIN;
       for(int i = 0 ; i < n ;i++){
          maxi = max(maxi,dp[i]);
       }
       return maxi;
    }

/////////////////////////////////////////////////////////// Optimal || T.C = O(n ^ logn) || S.C = O(N)  ///////////////////////////////////////////////////////


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       int dp[n+1];
       for(int i = 1 ; i <= n ; i++) dp[i] = INT_MAX;
       dp[0] = INT_MIN;
       
       for(int i = 0 ; i < n ; i++){
           int idx = upper_bound(dp , dp+n+1 , a[i]) - dp;
           if( dp[idx-1] < a[i] && dp[idx] > a[i] ){
               dp[idx] = a[i];
           }
       }
       
       int ma = 0;
       
       for(int i = n ; i >= 0 ; i--){
           if(dp[i] != INT_MAX){
               ma = i;
               break;
           }
       }
       return ma;
    }
};
