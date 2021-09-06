https://leetcode.com/problems/surrounded-regions/

class Solution {
    
    void dfs(vector<vector<char>>&board,int i,int j){
        if(board[i][j] == 'O'){
            board[i][j] = '1';
            
            if(i+1 < board.size())dfs(board,i+1,j);
            if(i > 1)dfs(board,i-1,j);
            if(j+1 < board[i].size())dfs(board,i,j+1);
            if(j > 1)dfs(board,i,j-1);
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0){
            return;
        }
        int row = board.size() , col = board[0].size();
        
        //First row And last row
        for(int i = 0 ; i < row ; i++){
            dfs(board,i,0);
            dfs(board,i,col-1);
        }
        
        //First col  And last Col
        for(int i = 0 ; i < col ; i++){
            dfs(board,0,i);
            dfs(board,row-1,i);
        }
        
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
