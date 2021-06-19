class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int  i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        // cout << n ;
        if(sum < target || (sum + target)%2!=0){
            return 0;
        }
        
        int s1 = (target + sum)/2;
        
        int dp[n+1][s1+1];
        
        for(int  i = 0 ; i <= s1 ; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= s1 ; j++){
                if(j < nums[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }
        
        return dp[n][s1];
        
    }
};
