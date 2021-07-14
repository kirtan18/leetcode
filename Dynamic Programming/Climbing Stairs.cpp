https://leetcode.com/problems/climbing-stairs/

/////////////////////////////////////////   Recursive  || T.C = O(2^N ) TLE  || S.C = O(1) ///////////////////////////////////

class Solution {
    
    int solve(int i , int n){
        if(i > n)return 0;
        if(i == n)return 1;
        
        return solve(i+1,n) + solve(i+2,n);
        
    }
    
public:
    int climbStairs(int n) {
        return solve(0,n);
    }
};


//////////////////////////////////  Botoom UP  || T.C = O(N)  || S.C = O(N)  //////////////////////////////
 

class Solution {
    
    int solve(int i , int n , vector<int>&mem){
        if(i > n) return 0;
        if(i == n) return 1;
        
        if(mem[i] != 0) return mem[i];
        
         mem[i] = solve(i+1,n,mem) + solve(i+2,n,mem);
         return mem[i];
    }
    
public:
    int climbStairs(int n) {
        vector<int>mem(n+1,0);
        return solve(0,n,mem);
    }
};


/////////////////////////////////////  Top - Down || T.C = O(N)  || S.C = O(N)  //////////////////////////////

class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 1)return 1;
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3 ; i <= n ; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};

////////////////////////////////////////////  Optimal || T.C = O(N)  || S.C = O(1)  ///////////////////////////////////
class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 1)return 1;
        int first = 1;
        int second = 2;
        
        for(int i = 3 ; i <= n ; i++){
            int third = first  + second;
            first  = second;
            second = third; 
        }
        return second;
        
    }
};
