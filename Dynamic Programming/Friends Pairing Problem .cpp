https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#

///////////////////////////////////////////////////  T.C = O(N) || S.C = O(N)  ///////////////////////////////////////////

public:
    int mod = 1000000007;
    int solve(int n , long long int dp[]){
        if(n <= 2)return n;
        if(dp[n] != -1)return dp[n];
        
        long long int a = (((n-1)%mod) * solve(n-2,dp)%mod)%mod ;
        long long int b =  solve(n-1,dp)%mod;
        
        return dp[n] = a+b;
    }
   
    int countFriendsPairings(int n) 
    { 
       long long int dp[n+1];
       memset(dp,-1,sizeof dp);
       return solve(n , dp) % mod;
    }
};     

/////////////////////////////////////////////////// T.C = O(N) || S.C = O(N) //////////////////////////////////////////////////

int dp[1000];

int countFriendsPairings(int n)
{
    if (dp[n] != -1)
        return dp[n];
 
    if (n > 2)
        return dp[n] = countFriendsPairings(n - 1) + (n - 1) * countFriendsPairings(n - 2);
    else
        return dp[n] = n;
}


/////////////////////////////////////////// Optimal || T.C = O(N)  || S.C = O(1)  ////////////////////////////////////////////////

public:
     int mod = 1000000007;
    int countFriendsPairings(int n) 
    { 
        int a = 1 , b = 2 , c = 0;
        
        if(n <= 2)return n%mod;
        
        for(int i = 3 ; i <= n ;i++){
             c = b + (i-1) * a ;
             a = b;
             b = c;
        }
        return c % mod;
    }
}; 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

public:
    int dp[1000009];
    int countFriendsPairings(int n) 
    { 
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        int mod = 1000000007;
        
        for(long long int i = 3 ; i <= n ;i++){
            
            dp[i] = ((dp[i-1])%mod+ (((i-1)%mod)*(dp[i-2])%mod))%mod;
            
        }
        return dp[n];
    }




