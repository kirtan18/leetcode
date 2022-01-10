// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int ans = 1e8;
        vector<int>pre(n,0);
        
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                cnt1++;
                pre[i] = 1;
            }
            if(i > 0) pre[i] += pre[i-1];
        }
        
        if(cnt1 == 0) return 0;
        
        for(int i=0;i<n;i++){
            int j = i+cnt1-1;
            int curr = 0;
            
            if(j < n){
                curr = pre[j];
                if(i>0)curr -= pre[i-1];
            }
            else{
                curr = pre[n-1];
                if(i>0) curr -= pre[i-1];
                j = j%n;
                curr += pre[j];
            }
            ans = min(ans,cnt1-curr);
        }
        return ans;
    }
};
