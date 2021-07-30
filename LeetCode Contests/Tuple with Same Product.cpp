https://leetcode.com/contest/weekly-contest-224/problems/tuple-with-same-product/



class Solution {
public:
    int tupleSameProduct(vector<int>& a) {
       
        int res = 0;
        map<int,int>mp;
        for(int i = 0 ; i < a.size() ; i++){
            for(int j = i+1 ; j < a.size() ; j++){
                res += (mp[a[i] * a[j]]++);
            }
        }
        return res * 8;
    }
};
