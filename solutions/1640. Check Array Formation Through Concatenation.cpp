class Solution {
public:
     // time == O(n)   space  == O(n)
    
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        unordered_map<int ,int>m;
        
        for(int i=0;i<arr.size();i++){
            m[arr[i]] = i;
        }
        for(auto a : pieces){
            int x = a[0];
            if(m.find(x) == m.end()) return false;
            
            int j = m[x];
            int i = 0;
            
            while(i<a.size() && j < arr.size()){
                if(a[i] != arr[j]) return false;
                i++;
                j++;
            }
            if(i != a.size())return false;
        }
        return true;
    }
};
