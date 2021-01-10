class Solution {
public:
    
    // time = O(n)   space = O(n)
    
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>map;
        
        for(int i : arr){
            map[i]++;
        }
        
        unordered_set<int>b;
        for(auto it= map.begin();it != map.end(); ++it){
            b.insert(it->second);
        }
        
        if(b.size() == map.size()){
            return true;
        }
        else{
            return false;
        }
    }
};
