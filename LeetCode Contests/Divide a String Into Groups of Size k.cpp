// https://leetcode.com/contest/weekly-contest-276/problems/divide-a-string-into-groups-of-size-k/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n = s.size();
        int d = k;
        int  j = 0;
        string put = "";
        string check = "";
        for(int i=0;i<n;i++){
            put += s[i];
            // check += s[i];
            d--;
            if(d == 0){
                ans.push_back(put);
                d = k;
                put = "";
                // check = "";
            }
            j++;
        }
        if(d > 0 && d != k){
            while(d > 0){
                put += fill;
                d--;
            }
            ans.push_back(put);
            return ans;
        }
        else{
            return ans;
        }
    }
};
