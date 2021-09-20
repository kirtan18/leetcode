https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/


class Solution {
    string checkBoard(vector<vector<char>>&board){
        
        //Check All Column
        for(int j = 0 ; j < 3 ; j++){
            
            int cntA = 0;
            int cntB = 0;
            
            for(int i = 0 ; i < 3 ; i++){
                if(board[i][j] == 'X') cntA++;
                else if(board[i][j] == 'O') cntB++;
            }
            
            if(cntA == 3)return "A";
            else if(cntB == 3)return "B";
        }
        
         //Check All Row
        for(int j = 0 ; j < 3 ; j++){
            
            int cntA = 0;
            int cntB = 0;
            
            for(int i = 0 ; i < 3 ; i++){
                if(board[j][i] == 'X') cntA++;
                else if(board[j][i] == 'O') cntB++;
            }
            
            if(cntA == 3)return "A";
            else if(cntB == 3)return "B";
        }
        
        //Check Diagonal
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')return "A";
        else if(board[0][0] == 'O' && board[1][1] == 'O' 
                && board[2][2] == 'O') return"B";
        
        //Check Diagonal
        if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')return "A";
        else if(board[2][0] == 'O' && board[1][1] == 'O' 
                && board[0][2] == 'O') return"B";
        
        //Check for Draw
        int cnt = 0;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(board[i][j] == 'X' || board[i][j] == 'O'){
                    cnt++;
                }
            }
        }
        
        if(cnt != 9){
            return "Pending";
        }
        else{
            return "Draw";
        }        
    }
    
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n= moves.size();
        vector<vector<char>>board(3,vector<char>(3));
        
        for(int i = 0 ; i < n ; i++){
            if(i % 2 == 0){
                board[moves[i][0]][moves[i][1]] = 'X';
            }else{
                 board[moves[i][0]][moves[i][1]] = 'O';
            }
        }
        
        return checkBoard(board);
        
    }
};
