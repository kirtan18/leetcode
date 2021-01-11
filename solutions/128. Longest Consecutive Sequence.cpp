class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        set<int>hashset;
        
        for(int i: nums){
            hashset.insert(i);
       }
        
       int longest= 0;
        
       for(int cur:nums){
         
         if(!hashset.count(cur-1)){
            
             int currentnum = cur;
             int currentstreak = 1;
             
             while(hashset.count(currentnum+1)){
                 currentnum += 1;
                 currentstreak += 1;
  
             }
             longest = max(longest, currentstreak);
         }
    
       }
        
        return longest;
    }
};
​
​
​
