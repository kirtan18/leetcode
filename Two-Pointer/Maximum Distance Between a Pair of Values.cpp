https://leetcode.com/contest/weekly-contest-240/problems/maximum-distance-between-a-pair-of-values/

T.C = O(Max(num1.size(), nums2.size()))
S.C = O(1)  

////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0 , j = 0 , ans = 0;
        while(i < nums1.size() && j < nums2.size()){
            
            if(nums1[i] <= nums2[j]){
                if(i <= j){
                    ans = max(ans,j-i);
                }
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
