https://leetcode.com/contest/weekly-contest-265/problems/minimum-operations-to-convert-number/

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int>q;
        int moves = 0;
        q.push(start);
        vector<bool>vis(1001,0);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int curr = q.front();
                q.pop();
                
                if(curr == goal){
                    return moves;
                }
                if(curr < 0  || curr > 1000 || vis[curr]){
                    continue;
                }
                
                vis[curr] = 1;
                for(int i=0;i<nums.size();i++){
                    q.push(curr + nums[i]);
                    q.push(curr - nums[i]);
                    q.push(curr ^ nums[i]);
                }
            }
            moves++;
        }
        return -1;
    }
};
