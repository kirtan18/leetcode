https://leetcode.com/problems/largest-plus-sign/


////////////////////////// T.C = O(N^2) /////////////////// S.C = O(4*n^2) //////////////////////////////////

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>mat(n,vector<int>(n,1));
        
        for(auto it : mines){
            int x = it[0];
            int y = it[1];
            mat[x][y] = 0;
        }
        
        vector<vector<int>>left,right,top,bot;
        
        left = right = bot = top = mat;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                
                int x = n - i - 1;
                int y = n - j - 1;
                
                if(i>0 && top[i][j]) top[i][j] += top[i-1][j];
                if(j>0 && left[i][j]) left[i][j] += left[i][j-1];
                if(y < n-1 && right[x][y]) right[x][y] += right[x][y+1];
                if(x < n-1 && bot[x][y]) bot[x][y] += bot[x+1][y];
                 
            }
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                ans = max(ans,min({left[i][j] , right[i][j] , top[i][j] , bot[i][j]}));
            }
        }
        return ans;
    }
};


//////////////////////////////// Using DP ////////// T.C = O(N^2) /////////////////// S.C = O(1) /////////////////////////////

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if(n*n == mines.size()){
            return 0;
        }
        
        int t[n][n];
        for(int i = 0 ; i < n ; i++){
            for(int j =  0 ; j < n ; j++){
                t[i][j] = n;
            }
        }
        
        for(auto it : mines){
            t[it[0]][it[1]] = 0;
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            //Lets count of left side
            int left = 0;
            for(int j = 0 ; j < n ; j++){
                left = t[i][j] == 0 ? 0 : left+1;
                t[i][j] = min(t[i][j],left);
            }
            
            //Lets count of right side
            int right = 0;
            for(int j = n-1 ; j >= 0 ; j--){
                right = t[i][j] == 0 ? 0 : right+1;
                t[i][j] = min(t[i][j],right);
            }
            
            //Lets count of top side
            int top = 0;
            for(int k = 0 ; k < n ; k++){
                top = t[k][i] == 0 ? 0 : top+1;
                t[k][i] = min(t[k][i],top);
            }
            
            //Lets count of bottom
            int bot = 0;
            for(int k = n-1 ; k >= 0 ; k--){
                bot = t[k][i] == 0 ? 0 : bot+1;
                t[k][i] = min(t[k][i],bot);
            }   
        }
        
        //Finally find max one
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                ans = max(ans,t[i][j]);
            }
        }
        
        return ans;
    }
};
