https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1#

///////////////////////////////////////////////////////////////  T.C = O(N) || S.C = O(1)  ////////////////////////////////////////////////////////////////

class Solution{
    public:
    long long countWays(int n, int k){
         long long MOD = 1000000007;
         
         if(n == 0)return 0;
         if(n == 1)return k;
         
         long long same = k % MOD;
         long long diff = (k * (k-1)) % MOD;
         
         for(long long i = 3 ; i <= n ; i++){
             
             long long prev = diff % MOD;
             diff = ((same + diff) * (k-1)) % MOD;
             same = prev % MOD;
         }
         return (same + diff) % MOD;
    }
};
