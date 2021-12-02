// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return;
        int i = 0;
        int m = 0;
        int j = n-1;
        
        while(m <= j){
            if(nums[m] == 0){
                swap(nums[i],nums[m]);
                m++;
                i++;
            }
            else if(nums[m] == 1){
                m++;
            } 
            else{
                swap(nums[m],nums[j]);
                j--;
            }
        }
    }
};
