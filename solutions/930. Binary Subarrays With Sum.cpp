class Solution {
public:
    // time == O(n)   space == O(n)
    
    int numSubarraysWithSum(vector<int>& A, int S) {
        int sum = 0;
        int count = 0;
        unordered_map<int,int> map;
        
        for(int i = 0 ; i < A.size() ; i++ ){
            sum += A[i];
            
           if(sum == S) count++;
        
            if(map.find(sum-S) != map.end()) {
                count +=  map[sum-S];
            }
            map[sum]++;
 
        }
        
        return count;
    }
};
