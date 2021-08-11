https://practice.geeksforgeeks.org/problems/bbt-counter4914/1#

//////////////////////////////////////////////////////////////////////////////// 
BruteForce
T.C = TLE
S.C = O(1)
  
class Solution {
  public:
    int MOD = 1000000007;
    long long int countBT(int h) { 
        if(h == 0 || h == 1){
            return 1;
        }
        return countBT(h-1) * (2*countBT(h-2) + countBT(h-1));
    }
};

/////////////////////////////////////////////////////////////////////////////////
Optimal
T.C = O(N)
S.C = O(N)
  
class Solution {
  public:
    long long int countBT(int h) { 
        int MOD = 1000000007;
        long long int dp[h+1];
        dp[0] = dp[1] = 1;
        for(int i = 2 ; i <= h ; i++){
            dp[i] = (dp[i-1] * ((2 * dp[i-2]) % MOD + dp[i-1])%MOD)%MOD;
        }
        return dp[h];
    }
};  


