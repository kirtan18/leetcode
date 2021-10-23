https://leetcode.com/problems/house-robber/


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int arr[nums.size()];
        arr[0] = nums[0];
        arr[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++)
            arr[i] = max(arr[i-1], arr[i-2]+nums[i]);
        
        return arr[nums.size()-1];
    }
};
