https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

///////////////////////////////////// Brute || T.C = O(N) || S.C = O(n) \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int first = -1, last = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                if(first == -1){
                    first = i;
                    last = i;
                }
                else
                    last = i;
            }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};


//////////////////////////////////// Brute2  || T.C = O(N) || S.C = O(N^2) \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2, -1);
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        int index = -1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target){
                index = i;
                break;
            }
        if(index != -1){
            ans[0] = index;
            ans[1] = index + mp[target] - 1;
        }
        return ans;
    }
};

///////////////////////////////////// Optimal || T.C = O(logn) || S.C = O(1)  /////////////////////////////////////////

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int start ,end;
        vector<int>ans;
        
        while(l <= r){
            
            int mid = (l+r)/2;
            
            if(nums[mid] == target){
                
                int temp = mid;
                while(mid > 0 && nums[mid-1] == target)mid--;
                start = mid;
                while(temp < n-1 && nums[temp+1] == target)temp++;
                end = temp;
                
                ans.push_back(start);
                ans.push_back(end);
                
                return ans;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }     
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
      
    }
};


