https://leetcode.com/problems/maximum-subarray/


/////////////////////////////////  Apply Kadanes algo  || T.C = O(N) || S.C = O(1) //////////////////////////////

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     
        int sum = nums[0];
        int maxi = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            
            sum = max(nums[i] , sum + nums[i]);
            maxi  = max(maxi,sum);
             
        }
        return maxi;
    }
};

////////////////////////////  DP   || T.C = O(N)  || S.C = O(N)   /////////////////////////////////////

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            dp[i] = max(nums[i] , nums[i] + dp[i-1]);
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};
