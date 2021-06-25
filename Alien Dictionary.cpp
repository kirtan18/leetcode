// https://practice.geeksforgeeks.org/problems/alien-dictionary/1#



Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
  
  
  
  b -> a
  d -> a
  a -> c
  b -> d
  
  after we connect in graph and then we can use toposort for this method    
//////////////////////////////////////////////////////////////////////////////////////////////////////  
  void dfs(int node, vector<vector<int>>&g , vector<int>&vis ,string&ans){
        vis[node] = 1;
        
        for(auto it : g[node]){
            if(!vis[it]){
                dfs(it,g,vis,ans);
            }
        }
        char ch = node + 'a';
        ans = ch + ans;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>>g(K);
        
        for(int i = 0 ; i < N -1 ; i++){
            string w1 = dict[i];
            string w2 = dict[i+1];
            
            for(int j = 0 ; j < min(w1.length(),w2.length()) ; j++){
                if(w1[j] != w2[j]){
                    g[w1[j] - 'a'].push_back(w2[j]-'a');
                    
                    break;
                }
            }
        }
        
        vector<int>vis(K,0);
        string ans = "";
        for(int i = 0 ; i < K ; i++){
            if(!vis[i]){
                dfs(i,g,vis,ans);
            }
        }
        return ans;
    }
