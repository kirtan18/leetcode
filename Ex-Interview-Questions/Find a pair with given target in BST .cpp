// https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1#

class Solution{
    int cnt = 0;
    bool solve(struct Node* root,int sum,unordered_set<int>&mp){
        if(root == NULL){
            return false;
        }
        if(mp.find(sum-root->data) != mp.end()){
            cnt++;
            return true;
        }
        else{
            mp.insert(root->data);
        }
        if(solve(root->left,sum,mp)){
            return true;
        }
        return solve(root->right,sum,mp);
    }
    
    
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        unordered_set<int>mp;    
        if(!solve(root,target,mp)){
            return 0;
        }
        return cnt;
    }
    
};
