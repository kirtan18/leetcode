https://leetcode.com/contest/biweekly-contest-58/problems/check-if-move-is-legal/



class Solution {
public:
    
    bool solve(vector<vector<char>>& board, int rMove, int cMove,int x , int y){
         
        int i = rMove + x;
        int j = cMove + y;
        int cnt = 0;
        
        while(i >= 0 && i < 8 && j >= 0 && j < 8){
            
            if(board[i][j] == '.'){
                return false;
            }
            
            if(board[i][j] == board[rMove][cMove]){
                if(cnt > 0){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                cnt++;
            }
            i += x;
            j += y;
        }
        return false;
    }
    
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        
        board[rMove][cMove] = color;
        
        vector<int>X = {-1,0,1,0,1,-1,-1,1};
        vector<int>Y = {0,1,0,-1,1,-1,1,-1};
        
        for(int i = 0 ; i < 8 ; i++){
            if(solve(board,rMove,cMove,X[i],Y[i])){
                return true;
            }
        }
         return false;
    }
};
