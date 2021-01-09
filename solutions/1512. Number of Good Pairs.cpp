class Solution {
public:
/*********   without map   *******************/
    
    // time == O(n)      space == O(1)
​
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j < nums.size();j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
     };
​
      /*******************  using hashmap ******************/
           // time == O(n)  space == O(n)
    
/*    
     int numIdenticalPairs(vector<int>& nums) {   
       unordered_map<int,int>map;
       int count = 0;
 
       
       for(int i=0;i<nums.size();i++){
         map[nums[i]]++;       
        }  
       
        for(auto x : map){
          count += x.second * (x.second-1)/2;
        }   
