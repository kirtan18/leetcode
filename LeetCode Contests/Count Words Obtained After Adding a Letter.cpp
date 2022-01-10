// https://leetcode.com/contest/weekly-contest-275/problems/count-words-obtained-after-adding-a-letter/

class Solution {
public:
    int wordCount(vector<string>& start, vector<string>& target) {
        int ans = 0;
        for(auto& x : start) sort(x.begin(),x.end());
        for(auto& y : target)sort(y.begin(),y.end());
        set<string>st {start.begin(),start.end()};
        int n = target.size();
        
        for(string &s : target){
            bool ok  = 0;
            for(int i=0;i<s.size();i++){
                string curr = s.substr(0,i)+s.substr(i+1);
                if(st.count(curr)){
                    ok = 1;
                    break;
                }
            }
            if(ok==1) ans++;
        }
        return ans;
    }
};
