https://leetcode.com/problems/binary-search-tree-iterator/

// To do so, I declare 3 class variables:

// curr is a pointer to which value we will "pop" next;
// pos will keep track of what position in store we will push into next and, at the end of the caching part, 
// it will also tell us how big is our store (so basically acting as a measure of its length);
// store, you guessed it, will store the values of each single node parsed.
// In our constructor we are going to call our helper dfs that will just:

// check if root is NULL, in which case we return;
// call itself on root->left;
// add root->val to store in position pos;
// increment pos by 1;
// call itself on root->right.
// The following methods are somehow trivial:

// next will just return store[curr] and increment it;
// hasNext will just return if curr < pos, meaning we can still pop at least a value.

class BSTIterator {
    
    int cur = 0 , pos = 0 , store[100001];
    void  dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);
        store[pos++] = root->val;
        dfs(root->right);
    }
    
public:
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        return store[cur++];
    }
    
    bool hasNext() {
        return cur < pos;
    }
};
