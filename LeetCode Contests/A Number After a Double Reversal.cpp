// https://leetcode.com/contest/weekly-contest-273/problems/a-number-after-a-double-reversal/

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num == 0){
            return true;
        }
        
        int last = num % 10;
        if(last == 0){
            return false;
        }
        return true;
    }
};
