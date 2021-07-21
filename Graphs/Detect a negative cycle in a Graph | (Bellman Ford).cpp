https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/



struct node{
    int u;
    int v;
    int wt;

    node(int first,int sec,int weight){
        u = first;
        v = sec;
        wt = weight;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<node>edge;
    
    for(int i  = 0 ; i < m ; i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edge.push_back(node(u,v,wt));
    }

    int src;
    cin >> src;

    int inf = 10000000;
    vector<int>dis(n,inf);

    dis[src] = 0;

    for(int i = 1 ; i <= n-1 ; i++){
        for(auto it : edge){
            if(dis[it.u] + it.wt > dis[it.v]){
                dis[it.v] = dis[it.u] + it.wt;
            }
        }
    }

    int fl = 0;

    for(auto it : edge){
       if(dis[it.u] + it.wt > dis[it.v]){
         cout << "Negetive Cycle";
         fl = 1;
         break;
       }
    }

    if(!fl){
        for(int i = 0 ; i < n ; i++){
            cout << i << " " << dis[i] << endl;
        }
    }
    
    return 0;
}
