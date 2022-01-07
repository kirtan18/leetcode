// https://leetcode.com/contest/weekly-contest-273/problems/execution-of-all-suffix-instructions-staying-in-a-grid/

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& pos , string s) {
        vector<int>ans;
        int x = pos[0];
        int y = pos[1];
        int m =  s.size();
        int cnt;
        
        for(int i=0;i<m;i++){
            cnt = 0;
            int x1=x;
            int y1=y;
            for(int j=i;j<m;j++){
     
                // for left side
                if(s[j] == 'L'){
                    if(y1-1 >= 0){
                        cnt++;
                        y1 = y1-1;
                    }
                    else{
                        break;
                    }
                }
                
                // for right side
                if(s[j] == 'R'){
                    if(y1+1 <= n-1){
                        cnt++;
                        y1 = y1+1;
                    }else{
                        break;
                    }
                }
                
                // for up side
                if(s[j] == 'U'){
                    if(x1-1 >= 0){
                        cnt++;
                        x1 = x1-1;
                    }else{
                        break;
                    }    
                }
                
                // for down side
                if(s[j] == 'D'){
                    if(x1+1 <= n-1){
                        cnt++;
                        x1 = x1+1;
                    }else{
                        break;
                    }
                }
                
            }
         
            ans.push_back(cnt);
        }
        return ans;
    }
};
