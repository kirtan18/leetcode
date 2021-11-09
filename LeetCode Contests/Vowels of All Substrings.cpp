https://leetcode.com/contest/weekly-contest-266/problems/vowels-of-all-substrings/




class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u';
    }
public:
    long long countVowels(string word) {
        long long ans = 0;
        long long n = word.size();
        for(long long i = 0 ; i < word.size() ; i++){
            if(isVowel(word[i])){
                ans += (i+1) * (n-i);
            }
        }
        return ans;
    }
};
