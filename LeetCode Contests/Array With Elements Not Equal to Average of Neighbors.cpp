https://leetcode.com/contest/weekly-contest-254/problems/array-with-elements-not-equal-to-average-of-neighbors/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        int l = 0 , r = nums.size()-1;
        
        while(l<r){
            v.push_back(nums[l++]);
            v.push_back(nums[r--]);
        }
        if(l == r)v.push_back(nums[l]);
        return v;
    }
};
