// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#



 	int LongestRepeatingSubsequence(string str){
		   
		    string b = str;
		    
		    int m = str.size();
		    int n = b.size();
		    
		    int dp[m+1][n+1];
		    
		    for(int i = 0 ; i <= m ; i++){
		        for(int j = 0 ; j <= n ; j++){
		            
		            if(i == 0 || j == 0)dp[i][j] = 0;
		            
		           else if(str[i-1] == b[j-1] && i != j){
		                dp[i][j] = dp[i-1][j-1] + 1;
		            }
		            
		            else{
		                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    
		    return dp[m][n];
		}
