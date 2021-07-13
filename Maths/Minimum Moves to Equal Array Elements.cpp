https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

/////////////////////////////////////////////////  T.C = O(N)  || S.C = O(1)   ///////////////////////////////////////////

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int mini = INT_MAX;
        
        for(auto i : nums){
            mini = min(mini,i);
        }
       
        int cnt = 0;
        for(auto i : nums){
            cnt += i - mini;
        } 
         
        return cnt;       
    }
};
