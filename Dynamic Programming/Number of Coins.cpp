// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#



int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[M+1][V+1];
	    
	    for(int i = 1 ; i <= V ; i++){
	        dp[0][i] = INT_MAX-1;
	    }
	    for(int i = 1 ; i <= M ;i++){
	        dp[i][0] = 0;
	    }
	   
	    for(int i = 1,j = 1 ; j <= V ; j++){
            if(j%coins[0] == 0){
              dp[i][j] = j/coins[0];
            }
            else{
              dp[i][j] = INT_MAX-1;
            }
        }
	    
	    for(int  i = 2 ; i <= M ; i++){
	        for(int j = 1 ; j <= V ; j++){
	            if(coins[i-1] > j){
	                dp[i][j] = dp[i-1][j];
	            }
	            else{
	                dp[i][j] = min(dp[i][j - coins[i-1]] + 1 , dp[i-1][j]);
	            }
	        }
	    }
	    if(dp[M][V]==INT_MAX - 1) return -1;
	  return  dp[M][V];
	} 
