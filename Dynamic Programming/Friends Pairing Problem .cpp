https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#

///////////////////////////////////////////////////  T.C = O(N) || S.C = O(N)  ///////////////////////////////////////////

class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        int dp[n + 1];
 
    for (int i = 0; i <= n; i++) {
        if (i <= 2)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
 
    return dp[n];
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



