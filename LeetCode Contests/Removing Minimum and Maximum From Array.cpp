https://leetcode.com/contest/weekly-contest-269/problems/removing-minimum-and-maximum-from-array/


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int x = 0 , y = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[x] < nums[i]) x = i;
            if(nums[y] > nums[i]) y = i;
        }
        
        return min({max(x+1,y+1) , max(n-x,n-y) , x+1+n-y , y+1+n-x});
    }
};
