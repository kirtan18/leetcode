https://practice.geeksforgeeks.org/problems/ncr1019/1#

//////////////////////////////////////////////////////  Brute || TLE  /////////////////////////////////////////

class Solution{
public:
    int nCr(int n, int r){
        if(r > n){
            return 0;
        }
        if( r == 0 || r == n)return 1;
        
        return nCr(n-1,r-1) + nCr(n-1,r);
        
    }
};


////////////////////////////////////////////////  T.C = O(n*r) || S.C = O(r)  ////////////////////////////////////

class Solution{
public:
    int nCr(int n, int r){
        if(r > n)return 0;
        if((n-r)>r) r = n -r;
        int MOD = 1000000007;
        int dp[r+1];
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        
        for(int i = 1; i <= n ; i++){
            for(int j = min(i,r) ; j >=0 ; j--){
                dp[j] = (dp[j] + dp[j-1]) %  MOD;
            }
        }
        return dp[r];
    }
};


////////////////////////////////////////////////////////////////////////////////

class Solution{
public:
    int nCr(int n, int k){
        int mod = 1000000007;
        long long int C[n + 1][k + 1]; 
        int i, j; 
        if(n < k) return 0;
      
        for (i = 0; i <= n; i++) 
        { 
            for (j = 0; j <= min(i, k); j++) 
            { 

                if (j == 0 || j == i) 
                    C[i][j] = 1; 
     
                else
                    C[i][j] = (C[i - 1][j - 1] +  C[i - 1][j]) % mod; 
            } 
        } 
      
        return C[n][k]; 

    }
};
