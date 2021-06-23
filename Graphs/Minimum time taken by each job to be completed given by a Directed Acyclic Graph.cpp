// https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/

10 13
1 3
1 4
1 5
2 3
2 9
2 8
3 6
4 6
4 8
5 8
6 7
7 8
8 10
  
output :   
  1 1 2 2 2 3 4 5 2 6 
    
    
void solve() {

     int v,e;
     cin >> v >> e;
     vector<int>g[v+1];
     vector<int>indegree(v+1,0);
     for(int i = 0 ; i < e ; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        indegree[y]++;
     }

     vector<int>ans(v+1,0);
     queue<int>q;

     for(int i = 1 ; i <= v ; i++){
        if(indegree[i] == 0){
            q.push(i);
            ans[i] = 1;
        }
     }
     
     while(!q.empty()){
        int val = q.front();
        q.pop();
        for(auto x : g[val]){
            indegree[x]--;
            if(indegree[x] == 0){
                ans[x] = ans[val] + 1;
                q.push(x);
            }
        }
     }
    for(int i = 1 ; i <= v ; i++)cout << ans[i] <<" ";
 }

 

