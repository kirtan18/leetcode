class Solution {
public:
   // time  == O(N) space == O(1)
    
    bool kLengthApart(vector<int>& nums, int k) {
        int val = 0;
        int len = 0;
       
        for(int i =0 ;i<nums.size();i++){
            
            if(nums[i] == 1){
                if(val == 0){
                    val++;
                  
                }
                else{
                    int x = len - val;
                    if(x < k){
                        return false;
                    }
                    len = 0;
                    val = 1;
                    }
                   
                }
            len++; 
            }            
         return true;            
    } 
};
​
​
​
///// yukta's  method 
/*
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = k ;
        for(auto i : nums){
            
            if(i == 1){
                
                if(count < k)
                    return false;
                
                count = 0 ;
                
            }
            
            else{
                count++;
            }
            
        }
        
        return true;
        
    }
};
*/
