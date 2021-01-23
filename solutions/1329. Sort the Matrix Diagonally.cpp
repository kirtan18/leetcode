class Solution {
public:
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         int n = mat.size();
        int m = mat[0].size();
        int x,y;
        
        // moving columnwise
        for(int i = 0; i < m; i++) {
            vector<int> temp;
            x = i;
            y = 0;
            while(x < m && y < n) {
                temp.push_back(mat[y][x]);
                x++;
                y++;
            }
            sort(temp.begin(), temp.end());
            x = i;
            y = 0;
            int count = 0;
            while(x < m && y < n) {
                mat[y][x] = temp[count];
                x++;
                y++;
                count++;
            }
        }
​
        
        // moving rowwise
        for(int i = 1; i < n; i++) {
            vector<int> temp;
            x = 0;
            y = i;
            while(x < m && y < n) {
                temp.push_back(mat[y][x]);
                x++;
                y++;
            }
            sort(temp.begin(), temp.end());
            x = 0;
            y = i;
            int count = 0;
            while(x < m && y < n) {
                mat[y][x] = temp[count];
                x++;
                y++;
                count++;
            }
        }
​
        return mat;
        
    }
};
