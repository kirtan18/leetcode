https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

class Solution{
    
    bool subsetSum(int N , int arr[] , int sum){
        bool dp[N+1][sum+1];
        
        for(int i = 0 ; i <= N ;i++){
            dp[i][0] = true;
        }
        
        for(int j = 0 ; j <= sum ; j++){
            dp[0][j] = false;
        }
        
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= sum ; j++){
                if(j >= arr[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else if(j < arr[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][sum];       
    }
 
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i = 0 ; i < N ; i++){
            sum += arr[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
        else {
            return subsetSum(N,arr,sum/2);
        }      
    }
};

