class Solution {
public:
    // [1,3,2,2,5,2,3,7]
    // time == O(n)  space == O(n)
    
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        for(auto i : nums){
            mp[i]++;
        }
        
        int maxl = 0;
        
        for(auto & [num,f] : mp){
           if(mp.find(num+1) != mp.end()){
               maxl = max(maxl, f + mp[num +1] );
           }
        }
        
        return maxl;
    }
};
​
   // in java but brute force   time = O(n2)  space = O(1)
​
/*
public class Solution {
    public int findLHS(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            boolean flag = false;
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] == nums[i])
                    count++;
                else if (nums[j] + 1 == nums[i]) {
                    count++;
                    flag = true;
                }
            }
            if (flag)
                res = Math.max(count, res);
        }
        return res;
    }
}
*/
