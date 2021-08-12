https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#

//////////////////////////////// kadane's algorithm///////////////////////
// T.C = O(N) || S.C = O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            maxi = max(maxi,sum);
            
            if(sum<0) sum=0;
            
        }
        return maxi;
      
    }
};

///////////////////////using dp/////////////////
//  T.C = O(N) || S.C = O(N) 
  
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();        
        int dp[n];
        
        dp[0] = nums[0];
        int maxi = nums[0];
        
        for(int i = 1 ;i < n ; i++){
            dp[i] = max(nums[i] , nums[i] + dp[i-1]);
            maxi = max(maxi , dp[i]);
        }
        return maxi;
        
    }
};
