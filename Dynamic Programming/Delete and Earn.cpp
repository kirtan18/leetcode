https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>cn(mx+1,0);
        for(auto x:nums)cn[x]++;
        
        vector<int>dp(mx+1);
        dp[0]=0;
        dp[1]=cn[1];
        
        for(int i=2;i<mx+1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+cn[i]*i);
        }
        return dp[mx];

    }
};

/////////////////////////////////////////////////////////////////

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int>sum(10005,0);
        for(int i=0;i<nums.size();i++){
            sum[nums[i]] += nums[i];
        }
        
        vector<int>dp(10005);
        dp[1] = sum[1];
        dp[2] = max(sum[1],sum[2]);
        
        for(int i=3;i<10005;i++){
            dp[i] = max(sum[i] + dp[i-2],dp[i-1]);
        }
        return max(dp[10004],dp[10003]);
    }
};
