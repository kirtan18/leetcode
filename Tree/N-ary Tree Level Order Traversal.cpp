https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3871/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)return {};
        queue<Node*>q;
        vector<vector<int>>ans;
        vector<int>temp;
        
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                 Node * curr = q.front();
                 q.pop();
                 temp.push_back(curr->val);
                for(Node*child : curr->children){
                    q.push(child);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
