class Solution {
public:
    // time = O(n)  space == O(1)
    
     bool isMonotonic(vector<int>& A) {
         bool incresing = true;
         bool decresing = true;
       for(int i=0;i<A.size()-1;i++){
           if(A[i] > A[i+1])
               incresing = false;
           if(A[i] < A[i+1])
               decresing = false;
       }
         return incresing || decresing;
    }
};
    
    
   
    
    // time == O(n)  space = O(1)
  /*  
    bool incresing(vector<int>& A){
        for(int i=0;i<A.size()-1;i++)
            if(A[i] > A[i+1]) return false;
        return true;      
        
    }
    
    bool decresing(vector<int>& A){
        for(int i=0;i<A.size()-1;i++)
            if(A[i] < A[i+1])return false;
        return true;    
        
    }
