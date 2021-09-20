https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        if(n == 0)return i;
        for(int j = 1 ; j < n ; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
