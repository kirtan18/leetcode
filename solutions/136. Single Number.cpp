class Solution {
public:
//////////////******   using bit mani      ************////////
    
    // time == O(n)   space == O(1)
    
    int singleNumber(vector<int>& nums) { 
     
      int ans  = 0;
      
        for(int i=0;i<nums.size();i++){
            ans  ^= nums[i] ;
        }
        return ans;
     }
    };
    
    
    
    
    
    
    
    ///////////********  using hashtable *****************//////////
    /////// *  time = O(n)  space = O(n)  **********//////////
/*    
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>map;
    
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(int i=0; i<nums.size();i++){
          if ( map[nums[i]] == 1 ){
               return  nums[i];
