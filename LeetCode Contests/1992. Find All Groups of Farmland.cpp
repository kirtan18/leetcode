https://leetcode.com/contest/biweekly-contest-60/problems/find-all-groups-of-farmland/

////////////////////////////////////////////////////  Using DFS  //////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int n = land.size();
        int m = land[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(land[i][j] == 1){
                    
                   int endi = i , endj = j;
                   dfs(land,i,j,endi,endj);
                   ans.push_back({i,j,endi,endj}); 
                }
            }
        }
        return ans;
    }
  
    void dfs(vector<vector<int>>& land , int i,int j,int &endi,int &endj){
        
          int r = land.size(), c = land[0].size();
         
         if(i<0 || j<0 || i>r-1 || j>c-1 || land[i][j] == 0){
             return;
         }
         
         endi = max(endi,i);
         endj = max(endj,j);
        
         land[i][j] = 0;
        
        dfs(land,i-1,j,endi,endj);
        dfs(land,i+1,j,endi,endj);
        dfs(land,i,j-1,endi,endj);
        dfs(land,i,j+1,endi,endj);
     }
};

////////////////////////////////////////////////////////////////  Iterative Approch ///////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        
        int n = land.size();
        int m = land[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(land[i][j] == 0)continue;
                
                if(land[i][j] == 1){
                    int c1 = j;
                    while(c1 < m && land[i][c1] == 1){
                        c1++;
                    }
                    
                    int r1 = i;
                    while(r1 < n && land[r1][j] == 1){
                        r1++;
                    }
                    
                    // {r1,c1} = {i,j}
                    // {r2,c2} = {r1,c1}
                    
                    c1 = c1 == 0 ? c1 : c1-1;
                    r1 = r1 == 0 ? r1 : r1-1;
                    
                    ans.push_back({i,j,r1,c1});
                    
                    for(int k = i ; k <= r1 ; k++){
                        for(int l = j ; l <= c1 ; l++){
                            land[k][l] = 0;
                        }
                    }
                }               
            }
        }
        return ans;
    }
};





