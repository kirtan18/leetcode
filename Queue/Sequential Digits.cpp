// https://leetcode.com/problems/sequential-digits/

//////////////// T.C = O(45) || S.C = O(45) ////////////////////////

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        vector<int>ans;
        for(int i=1;i<=9;i++)q.push(i);
        bool done = 0;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int p = q.front();
                q.pop();
                if(p >= low && p <= high){
                    ans.push_back(p);
                }
                if(p > high){
                    done = 1;
                    break;
                }
                int rem = p % 10;
                if(rem<9){
                    p = (p*10 + rem + 1);
                    q.push(p);
                }
            }
            if(done == 1){
                break;
            }
        }
        return ans;
    }
};
