// time == O(n)  space == O(n)
​
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i = 0 ; i < numRows ; i++){
            vector<int> row(i + 1, 1);
            
            for(int j = 1 ; j < i ; j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(row);
        }
        
        return ans;
    }
};
​
​
// striver's method  
/*
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r (numRows);
        
        for(int i=0; i<numRows;i++){
          r[i].resize(i+1);
          r[i][0] = r[i][i] = 1;  
        
        
        for(int j = 1; j < i ;j++)
            r[i][j] = r[i-1][j-1] + r[i-1][j];
