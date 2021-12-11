// https://leetcode.com/contest/biweekly-contest-67/problems/find-good-days-to-rob-the-bank/


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int n = s.size();
        vector<int>ans;
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        
        pre[0] = 1;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(s[i] <= s[i-1]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            pre[i] = cnt;
        }
        
        suf[n-1] = 1;
        cnt = 1;
        for(int i=n-2;i>=0;i--){
            if(s[i] <= s[i+1]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            suf[i] = cnt;
        }
        
        for(int i=0;i<n;i++){
            if(pre[i]-1 >= time && suf[i]-1 >= time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
