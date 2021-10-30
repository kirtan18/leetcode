https://leetcode.com/contest/biweekly-contest-64/problems/plates-between-candles/



class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int cnt = 0 , left_ind = -1 , right_ind = -1;
        int n = s.size();
        vector<int>plate(n,0);
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        for(int i = 0 ; i < n ; i++){
            
            if(s[i] == '|'){
                left_ind = i;
            }
            left[i] = left_ind;
            
            if(s[i] == '*'){
                cnt++;
            }
            
            plate[i] = cnt;
        }
        
        for(int i=n-1;i>=0;i--){
            if(s[i] == '|'){
                right_ind = i;
            }
            right[i] = right_ind;
        }
        
        vector<int>ans;
        for(auto it : queries){
            int l = right[it[0]];
            int r = left[it[1]];
            if(l == -1 || r == -1 || l >= r)ans.push_back(0);
            else ans.push_back(plate[r] - plate[l]);
        }
        return ans;
    }
};
