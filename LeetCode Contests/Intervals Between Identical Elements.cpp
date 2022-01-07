// https://leetcode.com/contest/weekly-contest-273/problems/intervals-between-identical-elements/

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int , long long>cntMap,sumMap;
        int n = arr.size();
        
        vector<long long>ans(n,0);
        
        for(int i=0;i<n;i++){
            ans[i] += (cntMap[arr[i]] *i * 1LL - (sumMap[arr[i]]));
            cntMap[arr[i]]++;
            sumMap[arr[i]] += i;
        }
        
        sumMap.clear();
        cntMap.clear();
        
        for(int i=n-1;i>=0;i--){
            ans[i] += sumMap[arr[i]] - (cntMap[arr[i]] *i * 1LL);
            cntMap[arr[i]]++;
            sumMap[arr[i]] += i;
        }
        return ans;
    }
};
