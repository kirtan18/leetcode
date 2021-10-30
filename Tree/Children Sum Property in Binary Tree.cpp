https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=30&t=1s

////////////////////////////  T.C = O(N) /////////////////////////////////


void changeTree(BinaryTreeNode <int>* root){
    if(!root)return;
    int child = 0;
    if(root->left)child += root->left;
    if(root->right)child += root->right;
    if(child == root->val){
        root->val = child;
    }
    else{
        if(root->left)root->left->val = root->val;
        else if(root->right)root->right->val = root->val;
    }
    changeTree(root->left);
    changeTree(root->rigth);
    int tot = 0;
    if(root->left)tot += root->left;
    if(root->right)tot += root->right;
    if(root->left || root->right)root->val = tot;
}   
