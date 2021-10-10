https://leetcode.com/contest/weekly-contest-262/problems/two-out-of-three/


class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int>m1,m2,m3,m;
        vector<int>ans;
        for(int i = 0 ; i < nums1.size();i++){
            m1[nums1[i]]++;
            m[nums1[i]]++;
        }
        
        for(int i = 0 ; i < nums2.size();i++){
            m2[nums2[i]]++;
            m[nums2[i]]++;
        }
        
        for(int i = 0 ; i < nums3.size();i++){
            m3[nums3[i]]++;
            m[nums3[i]]++;
        }
        
        for(auto i : m){
            int val = 0;
            
            if(m1[i.first] > 0){
                val++;
            }
            if(m2[i.first] > 0){
                val++;
            }
            if(m3[i.first] > 0){
                val++;
            }
            if(val >=2 ){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
