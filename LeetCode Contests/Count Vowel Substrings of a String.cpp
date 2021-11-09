https://leetcode.com/contest/weekly-contest-266/problems/count-vowel-substrings-of-a-string/


/////////////////////////////////////////// Brute Force /////////////////////////////////////

class Solution {
public:
    int countVowelSubstrings(string word) {
        int sum = 0;
        
        for(int i = 0 ; i < word.size() ; i++){
            set<char>v;
            for(int j=i;j<word.size();j++){
                if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u'){
                    v.insert(word[j]);
                    if(v.size() >= 5)sum++;
                }
                else{
                    break;
                }
            }
        }
        
        return sum;
    }
};


////////////////////////////////////////// Optimal /////////////////////////////////////////
class Solution {
    private:
       bool isVowel(char ch){
           return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
       }
    private:
      int countAtMostKvowels(string s,int k){
          int i= 0;
          unordered_map<char,int>vowelMap;
          int cnt = 0;
          int n = s.size();
          
          for(int j=0;j<n;j++){
              if(!isVowel(s[j])){
                  vowelMap.clear();
                  i = j+1;
                  continue;
              }
              vowelMap[s[j]]++;
              cout << vowelMap.size() << " ";
              while(vowelMap.size() > k){
                  vowelMap[s[i]]--;
                  if(vowelMap[s[i]] == 0){
                      cout <<" "<< 1 << " " ;
                      vowelMap.erase(s[i]);
                  }
                  i++;
              }
              cnt += (j - i + 1);
          }
          cout << endl;
          return cnt;
      }
public:
    int countVowelSubstrings(string word) {
        return countAtMostKvowels(word,5) - countAtMostKvowels(word,4);
    }
};
