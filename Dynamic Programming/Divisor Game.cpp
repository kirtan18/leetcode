///////////////////////////////////   Recursive   Time : O(n^2)  space : O(1)   || TLE  ///////////////////////////////////


  int help(int n){
        if(n == 1) return  0;
        else{
            for(int i = 1 ; i < n ; i++){
                if(n%i == 0){
                    if(help(n-i) == 0)return 1;
                }
            }
        }
        return 0;
    }
    
public:
    bool divisorGame(int n) {
        return help(n);
    }


///////////////////////////////////  Memoization /////////////////////////////////////////////////////////////////////

 class Solution {
    int dp[1001];
    int help(int n){
        if(n == 1) return  0;
        if(dp[n] != -1)return dp[n];
        else{
            for(int i = 1 ; i < n ; i++){
                if(n%i == 0){
                    if(help(n-i) == 0)return dp[n] = 1;
                }
            }
        }
        return dp[n] = 0;
    }
    
public:
    bool divisorGame(int n){
        memset(dp,-1,sizeof dp);
        return help(n);
    }
};

////////////////////////////////  Fastest  /////////////////////////////////////////////

class Solution {
    int dp[1001];
    int help(int n){
        if(n == 1) return  0;
        if(dp[n] != -1)return dp[n];
        else{
            for(int i = 1 ; i*i <= n ; i++){
                if(n%i == 0){
                    if(help(n-i) == 0)return dp[n] = 1;
                    if(i != 1 && help(n-(n/i))==0)return dp[n] = 1;
                }
            }
        }
        return dp[n] = 0;
    }
    
public:
    bool divisorGame(int n){
        memset(dp,-1,sizeof dp);
        return help(n);
    }
};

//////////////////////////////// Time : O(1)  Space : (1)  //////////////////////////////////////////

class Solution {
public:
    bool divisorGame(int n) {
        return n%2 == 0;
    }
};




