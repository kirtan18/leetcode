class Solution {
public:
    
    /*****************  DFS   ******************/
    
    int maxi =0;
    void helper(Node * root , int level){
        if(!root) return;
        
        maxi = max(maxi,level);
        
        for(auto n : root->children){
            helper(n,level+1);
        }        
    }
    
    int maxDepth(Node* root) {
        
     helper(root,1);
     return maxi;   
         
    }
};
 
​
  /******************* BFS ****************/
    // time == O(N) space == O(N)
 /*   int maxDepth(Node* root) {
     queue<Node*>q;
     int d = 0;
     
     if(!root) return NULL;
     
     q.push(root);
     while(!q.empty()){
         int n = q.size();
         
         for(int i=0;i<n;i++){
             Node * curr = q.front();
             q.pop();
             for(auto  child : curr->children){
                 q.push(child);
             }
         }
         d++;
     }
   return d;
         
  }
};      */
