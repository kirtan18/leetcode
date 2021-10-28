  /////////////////////////////////////////////////////////////// Hard //////////////////////////////////////////////////////////////


 
 /////////////////////////////////////////////////////////////// Using BFS /////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////// Time : O(logn)*O(logn)*O(logn)*O(n) for both approch ///////////////////////////////////////////////////////////////////////////

 class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>todo;
        todo.push({root,{0,0}});
        
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode * node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            mp[x][y].insert(node->val);
            
            if(node->left){
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                todo.push({node->right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>>ans;
        for(auto p : mp){
            vector<int>temp;
            for(auto q : p.second){
                temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

   ////////////////////////////////////////////////////////////////  DFS  ////////////////////////////////////////////////////////////////////////////////
 
    map<int,map<int,set<int>>> mymap;

     void solve(TreeNode* curr,int col ,int row){
         if(!curr)
         	return;

         mymap[col][row].insert(curr->val);
         solve(curr->left,col-1,row+1);
         solve(curr->right,col+1,row+1);

     }


     vector<vector<int>> verticalTraversal(TreeNode* root) {
     
     solve(root,0,0);

     vector<vector<int>>ans;

     for(auto m1 : mymap){
     	ans.push_back(vector<int>());
          for(auto m2 : m1.second){
          	for(auto m3 : m2.second){
          		ans.back().push_back(m3);
          	}
          }
     }       
    return ans;    
    }
