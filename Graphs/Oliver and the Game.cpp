https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/

///////////////////////////////////////////////////////////////// T.C = O(V+E) || S.C = O(N) ///////////////////////////////////////////////////////////

vector<int>inTime;
vector<int>outTime;
int timer = 1;

void resize(int n){
    inTime.resize(n+1);
    outTime.resize(n+1);
}

void dfs(int src , int par , vector<int>g[]){
     inTime[src] = timer++;
     for(auto x : g[src]){
        if(x != par){
            dfs(x,src,g);
        }
     }
     outTime[src] = timer++;
}

bool check(int x,int y){
    if(inTime[x] > inTime[y] and outTime[x] < outTime[y]){
        return true;
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    resize(n);
    vector<int>g[n+1];
    for(int i = 0 ; i < n-1 ; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,g);
    int q;
    cin >> q;

    for(int i = 0 ; i < q ; i++){
        int type,x,y;
        cin >> type >> x >> y;
        
        if(!check(x,y) and !check(y,x)){
            cout << "NO" <<"\n";
            continue;
        }

        if(type == 0){
            if(check(y,x)){
                cout << "YES"<<"\n";
            }
            else{
                cout << "NO" <<"\n";
            }
        }

        else if(type == 1){
            if(check(x,y)){
                cout << "YES" <<"\n";
            }
            else{
                cout << "NO" <<"\n";
            }
        }
    }

}

signed main(){
#ifndef ONLINE_JUDGE
freopen("input1.txt", "r", stdin);
freopen("output1.txt", "w", stdout);
#endif 
   
    // int T;
    // cin >> T;
    // while(T--){
       solve();
    // }
    return 0;
}
