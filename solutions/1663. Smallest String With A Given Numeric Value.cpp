​
class Solution {
public:
    string getSmallestString(int n, int k) {
        //string result;
        string result(n, 'a');
        k -= n;
​
        
        while(k>0){
            result[--n] += min(25,k);
            k -= min(25,k);
        }
        
        return result;
    }
};
