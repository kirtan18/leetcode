// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1


////// Recursive 

class Solution
{  
    int cutSeg(int n , int x , int y , int z , int dp[]){
        
        if(n == 0)return 0;
        
        if(dp[n] != -1)return dp[n];
        
        int op1 = INT_MIN , op2 = INT_MIN , op3 = INT_MIN;
        if(n >= x) op1 = cutSeg(n-x,x,y,z,dp);
        if(n >= y) op2 = cutSeg(n-y,x,y,z,dp);
        if(n >= z) op3 = cutSeg(n-z,x,y,z,dp);
        
        return dp[n] = 1 + max(op1 , max(op2,op3));
        
    }
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        
        int a = cutSeg(n,x,y,z,dp);
        if(a < 0)return 0;
        return a;
    }
};




//  Knapsack unbounded method

int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;

        for (int i = 0; i <= n; i++) {
     
            if (dp[i] == -1)
                continue;
     
            if (i + x <= n)
                dp[i + x] = max(dp[i + x], dp[i] + 1);
    
            if (i + y <= n)
                dp[i + y] = max(dp[i + y], dp[i] + 1);
     
            if (i + z <= n)
                dp[i + z] = max(dp[i + z], dp[i] + 1);
        }
        
        if(dp[n] == -1) {
          dp[n] = 0;
        }
    
        return dp[n];
      
    }
