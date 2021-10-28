https://leetcode.com/problems/boundary-of-binary-tree/




 bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
 }

void left_view(TreeNode*root,vector<int>&ans){
    TreeNode * curr = root->left;
    while(curr){
        if(!isLeaf(curr))ans.push_back(curr->data);
        if(curr->left)curr = curr->left;
        else curr = curr->right;
    }
}

void leave_node(TreeNode*root,vector<int>&ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left)leave_node(root->left,ans);
    if(root->right)leave_node(root->right,ans);
}

void right_view(TreeNode*root,vector<int>&ans){
    vector<int>temp;
    TreeNode * curr = root->right;
    while(curr){
        if(!isLeaf(curr))temp.push_back(curr->data);
        if(curr->right)curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size()-1 ; i >= 0 ; i--){
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(!root)return ans;
    if(!isLeaf(root))ans.push_back(root->data);
    left_view(root,ans);
    leave_node(root,ans);
    right_view(root,ans);
    return ans;
}

