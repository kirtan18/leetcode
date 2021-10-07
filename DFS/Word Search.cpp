https://leetcode.com/problems/word-search/



class Solution {
    
 bool dfs(int idx,int x,int y,vector<vector<char>>& board, string &word){
     
     if(idx == word.size()){
         return true;
     }
     
     if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == '0' ||             board[x][y] != word[idx]){
         return false;
     }
     
     char temp = board[x][y];
     board[x][y] = '0';
     
     if(dfs(idx + 1 , x - 1 , y , board , word) or 
        dfs(idx + 1 , x + 1 , y , board , word) or 
        dfs(idx + 1 , x , y - 1 , board , word) or 
        dfs(idx + 1 , x , y + 1 , board , word)) {
            return true;
        }
      
     board[x][y] = temp;
     return false;   
     
 }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(dfs(0,i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
