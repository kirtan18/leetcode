https://leetcode.com/problems/find-all-duplicates-in-an-array/

1st app  : O(N^2) ==> using two loop and check the value

2nd  app = O(NlogN)  ==> sort and then check the ext value is same the this one is also ans so on

3rd app = O(N) || S.C = O(N) using map  count all var and check which one is greater than 1 then is one is our ans


4th == >  O(N) || S.C = O(1)
  
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0 ; i < nums.size() ; i++){
            int idx = abs(nums[i])-1;
            if(nums[idx] < 0){
                ans.push_back(abs(nums[i]));
            }
            nums[idx] =- nums[idx];
        }
        return ans;
    }
};

