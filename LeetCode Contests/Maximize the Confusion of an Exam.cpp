https://leetcode.com/contest/biweekly-contest-62/problems/maximize-the-confusion-of-an-exam/



class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int ans = 0;
        int l = 0;
        int cntf = 0;
        int n = key.size();
        
        // For F
        for(int i = 0 ; i < n ; i++){
            if(key[i] == 'F')cntf++;
            
            while(cntf > k){
                if(key[l] == 'F')cntf--;
                l++;
            }
            
            ans = max(ans,i-l+1);
        }
        
        // For T
        int cntT = 0;
        l = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(key[i] == 'T')cntT++;
            
            while(cntT > k){
                if(key[l] == 'T')cntT--;
                l++;
            }
            
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};
