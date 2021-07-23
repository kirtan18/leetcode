https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1


int maxSumIS(int nums[], int n)  
	{  
	    int dp[n];
	    for(int i = 0 ; i < n ; i++)dp[i] = nums[i];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
               if(nums[j] < nums[i]){
                   dp[i] = max(dp[i] , dp[j]+nums[i]);
               }
            }
        }
        
        int maxi =  0;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi,dp[i]);
        }
        return maxi;
	}  
