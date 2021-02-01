class Solution {
public:
    // time == O(n)  
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        ans.push_back(first);
        for(int i=0;i<encoded.size();i++){
            first ^= encoded[i];
            ans.push_back(first);
        }
                
        return ans;        
    }
};
