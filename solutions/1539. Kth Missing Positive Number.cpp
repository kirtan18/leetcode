class Solution {
public:
    
    // time = O(n)  space = O(1)
    
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        if(n<1) return 1;
        
        for(int i=1,j =0; i < arr[n-1] ;i++){
            if(arr[j] == i) j++;
            else
                k--;
            
            if(k == 0) return i;
        }
        return arr[n-1]+k;
    }
};
 
​
    
    
/*************  time == O(n)   space == O(n)   **************////
  
    // using hashmap
 /*   
  int findKthPositive(vector<int>& arr, int k) {
   
    unordered_map<int,int>map;
    
    for(int i=0;i<arr.size();i++){
        map[arr[i]]++;
    }  
