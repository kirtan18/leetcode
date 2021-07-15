// Given the root of a binary tree, return the zigzag level order traversal of its nodes'
// values. (i.e., from left to right, then right to left for the next level and alternate between).


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Input: root = [1]
// Output: [[1]]
// Input: root = []
// Output: []


class Solution {
public:
    vector<vector<int>>ret;      
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        vector<int>temp;
        s1.push(root);
        int k = 0;
        
        while(!s1.empty() || !s2.empty()){
            
            if(k%2 == 0){
                while(!s1.empty()){
                    TreeNode * curr = s1.top();
                    s1.pop();
                    temp.push_back(curr->val);                    
                    if(curr->left)s2.push(curr->left);
                    if(curr->right)s2.push(curr->right);
                    
                }
                k++;
            }
            else if(k%2 != 0){
                while(!s2.empty()){
                    TreeNode * curr = s2.top();
                    s2.pop();
                    temp.push_back(curr->val);
                    
                    if(curr->right)s1.push(curr->right);
                    if(curr->left)s1.push(curr->left);
                }
                k++;
            }
            ret.push_back(temp);
            temp.clear();   
        }
        return ret;
    }
};



////////////////////////////////////////////// Using Queue ////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;    //Initialising queue , (for bfs mostly we use queue) 
        vector<vector<int>> ans;    //ans 2D vector
        int c=0;    //count variable
        if(!root)
            return ans; //To handle the edge test case i.e. if NULL tree is provided
        q.push(root);   //now we push the whole root node in the queue
        while(!q.empty())
        {
            int s = q.size();   //we take the size beforehand so that the changes made inside the loop doesnt affect , how many times it will run
            vector<int> vec;    //1D vector to store values 
            c++;    //we increase count vector every time we go to one layer deep 
            for(int i=1;i<=s;i++)
            {
                TreeNode *t = q.front();        
                q.pop();
                vec.push_back(t->val);  //we push the value of the current node to the 1D vector
                if(t->left)
                    q.push(t->left);    //if the left node of the root node is present , then push the left node in the queue
                if(t->right)
                    q.push(t->right);   //if the right node of the root node is present , then push the right node in the queue
            }
            if(c%2==0)  
                reverse(vec.begin(),vec.end()); //now , we took the count variable because there was a pattern in the output that the 1D vector in the 2D vector at even counts are reversed and thats how it was zigzag , so we check the condition and reverse it. 
            ans.push_back(vec); //here we push the 1D vector in the ans.
        }
        return ans; //returning the 2D vector as our ans 
    }
};




