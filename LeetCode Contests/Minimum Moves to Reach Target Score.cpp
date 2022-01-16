// https://leetcode.com/contest/weekly-contest-276/problems/minimum-moves-to-reach-target-score/

class Solution {
public:
    int minMoves(int tar, int maxDoubles) {
        int cnt = 0;
        int prev = tar;
        while(tar > 1 && maxDoubles > 0){
            if(tar % 2 == 0){
                tar = tar/2; 
                cnt++; 
                maxDoubles--;
            }
            else{
                 tar = tar-1;
                 cnt++;
            }
        }
        
        return cnt + (tar - 1);
    }
};
