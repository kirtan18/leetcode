
https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/674/


/////////////////////////////////////  T.C = O(N) || S.C = O(N) ///////////////////////////////////////////////

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>ans;
        
        int n = nums1.size();
        int m = nums2.size();
        
        if(n < m){
            for(auto it : nums1){
               mp[it]++;
            }
            
             for(int i = 0 ; i < nums2.size() ; i++){  
               if(mp[nums2[i]] >= 1){
                  ans.push_back(nums2[i]);
                  mp[nums2[i]] -= 1;
               }
            }
        }
        else{
            for(auto it : nums2){
               mp[it]++;
            }

             for(int i = 0 ; i < nums1.size() ; i++){
               if(mp[nums1[i]] >= 1){
                  ans.push_back(nums1[i]);
                  mp[nums1[i]] -= 1;
               }
            }
        }
        
        return ans;
    }
};


/////////////////////////////////////// T.C = O(Nlogn) || S.C = O(1) /////////////////////////////////////////////////

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = 0, j = 0;
        
        while(i < n && j < m){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
                if(i>=n && j >= m)return ans;
            }
            else if(nums1[i] > nums2[j]){
                j++;
             
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
        }
        return ans;
    }
};

