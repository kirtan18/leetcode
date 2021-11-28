https://leetcode.com/contest/biweekly-contest-66/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sx = startPos[0];
        int sy = startPos[1];
        int ex = homePos[0];
        int ey = homePos[1];
        int ans = 0;
        while(sx != ex){
            if(sx > ex){
                sx--;
            }
            else{
                sx++;
            }
            ans += rowCosts[sx];
        }
        
        while(sy != ey){
            if(sy > ey){
                sy--;
            }
            else{
                sy++;
            }
            ans += colCosts[sy];
        }
        return ans;
    }
};
