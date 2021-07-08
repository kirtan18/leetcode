https://leetcode.com/problems/find-peak-element/


///////////////////////////////////////// Optimal || T.C = O(logn) || S.C = O(1) //////////////////////////////////////////

class Solution {
public:
    int findPeakElement(vector<int>& nums) {     
        int n = nums.size();
        int l = 0;
        int r = n-1;  
        while(l < r){
            int mid = (l+r)/2;
            
            if(nums[mid] > nums[mid+1]){
                r = mid;
            }
            else{
                l = mid+1;
            }         
        }
        return l;
    }
};
