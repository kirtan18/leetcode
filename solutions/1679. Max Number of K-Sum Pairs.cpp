class Solution {
public:
    // time = O(n)
      int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int trg=k-nums[i];
            if(mp[trg]>0)
            {
                ans+=1;
                mp[trg]-=1;
            }
            else
            {
                mp[nums[i]]+=1;
            }
        }
        return ans;
    }
    
    
    //time  == O(nlogn)
    /*
    int maxOperations(vector<int>& nums, int k) {
        int i = 0;
        int j = nums.size()-1;
        int count = 0;
        sort(nums.begin(),nums.end());
        while(i<j){
            if(nums[i] + nums[j] == k){
                count++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j] < k){
                i++;
            }
            else if(nums[i]+nums[j] > k){
                j--;
            }
        }
        return count;
    }
    */
};
