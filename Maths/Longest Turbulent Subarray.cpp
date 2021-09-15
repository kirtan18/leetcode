https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3976/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int best = 0 , cnt = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            
            if(i >= 2 && ((arr[i-2] > arr[i-1] && arr[i-1] < arr[i]) || 
                          (arr[i-2] < arr[i-1] && arr[i-1] > arr[i])) ){
                cnt++;
            }
            else if(i >= 1 && arr[i-1] != arr[i]){
                cnt = 2;
            }
            else{
                cnt = 1;
            }
            
            best = max(best , cnt);
        }
        return best;
    }
};
