https://leetcode.com/contest/weekly-contest-254/problems/number-of-strings-that-appear-as-substrings-in-word/


class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int pos = 0,cnt = 0;;
        for(int i = 0 ; i < patterns.size() ; i++){
            if(word.find(patterns[i] ,pos) != string::npos){
                cnt++;
            }
        }
        return cnt;
    }
};
