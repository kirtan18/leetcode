https://leetcode.com/problems/number-of-provinces/

Follow this tutorial for understand the what logic behind of the problem :
https://leetcode.com/problems/number-of-provinces/discuss/873741/Simple-C%2B%2B-Solution-oror-Fully-Explained-at-begineers-level-oror-Easy-Understanding-of-UNION-concept


Time Complexity: O(N * N * log(N))
Space Complexity: O(N)
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////  
class Solution {
    
    int parent(int x , vector<int>&v){
        if(v[x] == -1)return x;
        return v[x] = parent(v[x],v);
    }
    
    void _union(int a, int b , vector<int>&v){
         
        int p_a = parent(a,v);
        int p_b = parent(b,v);
        
        if(p_a == p_b){
            return;
        }
        
        v[p_a] = p_b;
    }
    
public:
    int findCircleNum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        vector<int>v(n,-1);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 1){
                    _union(i,j,v);
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(v[i] == -1){
                cnt++;
            }
        } 
        return cnt;
    }
};  

