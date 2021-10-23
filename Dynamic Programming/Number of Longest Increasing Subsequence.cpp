https://leetcode.com/problems/number-of-longest-increasing-subsequence/

//////////////////////////////// T.C = O(N^2) ///////////////////////////////

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n+1,1);
        vector<int>cnt(n+1,1);
        
        int max_len = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(lis[j]+1 > lis[i]){
                        lis[i] = lis[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(lis[j]+1 == lis[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            max_len = max(max_len,lis[i]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(lis[i] == max_len){
                ans += cnt[i];
            }
        }
        return ans;
    }
};
