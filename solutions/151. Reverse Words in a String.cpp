class Solution {
public:
    // time == O(n)  space = O(n)
    string reverseWords(string s) {
       stringstream ss(s);
        string word;
        vector<string>v;
        
        while(ss>>word)
            v.push_back(word);
        
        string ans = "";
        for(int i = v.size()-1 ; i>=0 ;i--){
            ans += v[i] + ' ';
        }
        ans.erase(ans.end()-1);
        return ans;
    }
};
​
​
​
​
