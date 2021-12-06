// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
	   int c[2] = {0};
        int even = 0 ; 
        int odd = 0;
	   for(auto pos: position){ 
           if(pos % 2 == 0){
               even++;
           }
           else{
               odd++;
           }
       }
	   return min(even,odd);
  }
};
