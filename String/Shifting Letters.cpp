https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3968/



class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int shiftTime = 0;
        
        for(int i = s.size()-1 ; i >= 0 ; i--){
            shiftTime = (shiftTime + shifts[i]) % 26;
            s[i] = (s[i] - 'a' + shiftTime) % 26 + 'a';
        }
        return s;
    }
};
