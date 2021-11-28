https://leetcode.com/contest/biweekly-contest-66/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/


class Solution {
public:
    int minimumBuckets(string s) {
        int cnt = 0;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i] == 'H'){
                if(i-1 >= 0 && s[i-1] == 'B')continue;
                if(i+1 < n && s[i+1] == 'B')continue;
                
                if(i+1 < n && s[i+1] == '.'){
                    s[i+1] = 'B';
                }
                else if(i-1 >= 0 && s[i-1] == '.'){
                    s[i-1] = 'B';
                }
                else{
                    return -1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(s[i] == 'B'){
                cnt++;
            }
        }
        return cnt;
    }
};
