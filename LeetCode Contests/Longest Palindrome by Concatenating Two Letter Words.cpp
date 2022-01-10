// https://leetcode.com/contest/biweekly-contest-69/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution {
public:
    int longestPalindrome(vector<string>& word) {
        unordered_map<string,int>mp;
        int cnt = 0;
        
        for(auto i : word){
            string p = i;
            reverse(p.begin(),p.end());
            string rev = p;
            if(mp[rev] > 0){
                cnt += 4;
                mp[rev]--;
            }
            else{
                mp[i] += 1;
            }
        }
        
        for(auto it : mp){
            int sec = it.second;
            string ch = it.first;
            if(sec > 0 && ch[0] == ch[1]){
                cnt += 2;
                break;
            }
        }
        return cnt;
    }
};
