https://leetcode.com/problems/flood-fill/

class Solution {
    
    void flood(int i , int j , vector<vector<int>>& image , vector<vector<int>>&vis 
              , int PC , int NC , int row , int col){
        
        if(i < 0 || i >= row || j < 0 || j >= col)return;
        
        else if(image[i][j] != PC)return;
        
        else if(vis[i][j] == 1)return;
        
        else{
            
            vis[i][j] = 1;
            image[i][j] = NC;
            
            flood(i+1,j,image,vis,PC,NC,row,col);
            flood(i-1,j,image,vis,PC,NC,row,col);
            flood(i,j+1,image,vis,PC,NC,row,col);
            flood(i,j-1,image,vis,PC,NC,row,col);
        
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int row = image.size();
        int col = image[0].size();
        
        int prevColor = image[sr][sc];
        
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        flood(sr,sc,image,vis,prevColor,newColor,row,col);
        
        return image;
        
    }
};
