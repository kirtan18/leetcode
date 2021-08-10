https://leetcode.com/contest/weekly-contest-253/problems/remove-stones-to-minimize-the-total/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto it : piles)pq.push(it);
        int x , sum;
        
        while(k--){
            x = pq.top();
            pq.pop();
            x -= floor(x/2);
            pq.push(x);
        }
        
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
