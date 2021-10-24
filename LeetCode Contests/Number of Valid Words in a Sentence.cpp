https://leetcode.com/contest/weekly-contest-264/problems/number-of-valid-words-in-a-sentence/


class Solution {
    
    bool check(string s){
        for(auto i : s){
            if(i >= '0' && i <= '9')return false;
        }
        
        int hypen = 0;
        int n = s.size();
        
        for(auto i : s){
            if(i == '-')hypen++;
        }
        if(hypen >= 2)return false;
        for(int i=0;i<n;i++){
            if(s[i] == '-'){
                if(i == 0)return false;
                if(i == n-1)return false;
                if(s[i-1] < 'a' || s[i-1] > 'z' || s[i+1] < 'a' || s[i+1] > 'z'){
                    return false;
                }
            }
        }
        
        int pun = 0;
        for(auto i : s){
            if(i == '!' || i == '.' || i == ',')pun++;
        }
        if(pun >= 2)return false;
        if(pun == 1 && (s[n-1] != '!' && s[n-1] != '.' && s[n-1] != ','))return false; 
        
        return true;
    }
    
public:
    int countValidWords(string sen) {
        
        string word = "";
        int total = 0;
        sen.push_back(' ');
        int n = sen.size();
        
        for(int i=0;i<n;i++){
            if(sen[i] == ' '){
                if(word != ""){
                    total += (check(word) == true ? 1 : 0);
                }
                word = "";
            }
            else{
                word += (char)sen[i];
            }
        }
        return total;
    }
};
