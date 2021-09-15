https://leetcode.com/problems/shortest-bridge/



class Solution {
    
    void flood_fill(vector<vector<int>>& grid,int i,int j , vector<pair<int,int>>&r){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        r.push_back(make_pair(i,j));
        flood_fill(grid,i+1,j,r);
        flood_fill(grid,i,j+1,r);
        flood_fill(grid,i-1,j,r);
        flood_fill(grid,i,j-1,r);
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>>x;
        vector<pair<int,int>>y;
        int cnt = 0;
        
        for(int i = 0  ; i < grid.size() ; i++){
            for(int j  =  0 ;  j < grid[0].size() ; j++){
                
                if(grid[i][j] == 1){
                    cnt++;
                    if(cnt == 1){
                        flood_fill(grid,i,j,x);
                    }
                    else if(cnt == 2){
                        flood_fill(grid,i,j,y);
                    }
                }  
            }
        }
        
        //count_minimum Distance
        int dist_min = INT_MAX;
        
        for(int i = 0 ; i < x.size() ; i++){
            for(int j = 0 ;  j < y.size() ; j++){
                int dist  = abs(x[i].first - y[j].first) +
                            abs(x[i].second - y[j].second);
                cout << dist;
                if(dist < dist_min){
                    dist_min = dist;
                }
              }
          }
         return dist_min;
    }
};
