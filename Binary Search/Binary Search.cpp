// https://leetcode.com/problems/binary-search/

//////////////////////////////////////////  Brute || T.C = O(N) || S.C = O(1) \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};


////////////////////////////////////// Optimal || T.C = O(logn) || S.C = O(1) //////////////////////////////////


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int mid ;
        
        while(l <= r){
            mid = l + (r-l)/2;
            
            if(nums[mid] == target)return mid;
            
            else if(nums[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
            
        }        
        return -1;          
    }
};
