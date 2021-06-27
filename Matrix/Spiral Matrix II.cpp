// https://leetcode.com/problems/spiral-matrix-ii/

//   Time Comp : O(n2) , Space : O(1) 

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n,vector<int>(n));
        
        if(n == 0)return ans;
        int r1 = 0 , r2 = n-1;
        int c1 = 0 , c2 = n-1;
        int j = 1;
        while(r1 <= r2 && c1 <= c2){
            
            for(int i = c1 ; i <= c2 ; i++){
                ans[r1][i] = j;
                j++;
            }
            
            for(int i = r1+1 ; i <= r2 ; i++){
                ans[i][c2] = j;
                j++;
            }
            
            if(r1 < r2 && c1 < c2){
                
                for(int i = c2-1 ; i >= c1 ; i--){
                    ans[r2][i] = j;
                    j++;
                }
                
                for(int i = r2-1 ; i > r1 ; i--){
                    ans[i][c1] = j;
                    j++;
                }
              }  
            r1++;
            r2--;
            c1++;
            c2--;
    }
    return ans;    
    }
};
