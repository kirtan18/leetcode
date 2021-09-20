https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/


//////////////////////  T.C = O(N) || S.C = O(1) ///////////////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0 , n = prices.size()-1;
        int max_prof = 0 ,buy = 0,sell = 0;

        while(i < n){
            while(i < n && prices[i+1] <= prices[i])i++;
            buy = prices[i];
            
            while(i < n && prices[i+1] > prices[i])i++;
            sell = prices[i];
            
            max_prof += sell - buy;
        }
        return max_prof;
    }
};




///////////////////// T.C = O(N) || S.C = O(1) ///////////////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cnt = 0;
        for(int i = 1 ; i < n ; i++){
            cnt += max(0,prices[i] - prices[i-1]);
        }
       return cnt;
    }
};
