// https://leetcode.com/problems/fibonacci-number/


////////////////////////////    Recursion  Time : O(2^n) , Space : O(1)  ////////////////////////////////////


 int fib(int n) {
        if(n <= 1){
            return n;
        }
        return fib(n-1) + fib(n-2);
 }

/////////////////////////// Top-Down  Time : O(n) , space : O(n)  ///////////////////////////////////////////

  int fib(int n) {
        if(n < 2){
            return n;
        }
        
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }

//////////////////////// Using Two Var ||  Time : O(N) , Space : O(1)  //////////////////////////////////////


  int fib(int n) {
        if(n < 2){
            return n;
        }
        
        int x = 0 ;
        int y = 1;
        
        for(int i = 2 ; i <= n ; i++){
            y = x + y;
            x = y - x;
        }
        return y;
    }


