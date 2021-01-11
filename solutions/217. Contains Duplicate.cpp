class Solution {
public:
    // sorting    time == O(nlogn)   space == O(1)
    
     bool containsDuplicate(vector<int>& nums) {
           sort(nums.begin(), nums.end()); 
         
         for(int i=1;i<nums.size();i++){
             if(nums[i] == nums[i-1])return true;
         }
         return false;
     }
   };
   
    
    
    /****************   using  set ******************/
/*
   bool containsDuplicate(vector<int>& nums) {
        set<int> hashset;
        for(auto i : nums){
            if(hashset.find(i) != hashset.end()){
                return true;
            }
            
            hashset.insert(i);
            
        }
        return false;   
​
    }
};
*/
    
​
