// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/

///////////////////////////////////////////////// Bruteforce  || T.C =  O(N^2) || S.C = O(N) ////////////////////////////////////


 class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                pq.push(matrix[i][j]);
            }
        }
        
        while(pq.size() != k){
            pq.pop();
        }
        return pq.top();
    }
};

///////////////////////////////////////// Optimal || T.C = (Nlogn) || S.C = O(1) //////////////////////////////////////////////

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        
        while(l <= r){
            
            int mid = l + (r-l)/2 ,tmp = n-1 ,cnt = 0;
            
            for(int i = 0 ; i < n ; i++){
                while(tmp>=0 && matrix[i][tmp] > mid)tmp--;
                cnt += tmp + 1;
            }
            
            if(cnt < k)l = mid+1;
            else{
                r = mid-1;
            }          
        }      
      return l;  
    }
};
