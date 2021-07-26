https://practice.geeksforgeeks.org/problems/max-length-chain/1#

///////////////////////////////////////////////////////////// T.C = O(N^2) || S.C = O(N)  ////////////////////////////////////////////////////////

int maxChainLen(struct val a[],int n)
{
    int dp[n];
    vector<pair<int ,int> >p;
    
    for(int i = 0 ; i < n ; i++){
        p.push_back({a[i].first,a[i].second});
    }
    sort(p.begin(),p.end());
    
    for(int i = 0 ; i < n ; i++)dp[i] = 1;
    
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            
            if(a[j].second < a[i].first && dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1;
            }
        }
    }
    int max = 0;
    for(int  i = 0 ; i < n ; i++){
        if(max < dp[i]){
            max = dp[i];
        }
    }
    
    return max;
}


///////////////////////////////////////////////////////////// T.C = O(N) || S.C = O(N) ////////////////////////////////////////////////////////////////////

bool comp(pair<int,int>a , pair<int,int> b){
    return a.second < b.second;
}

int maxChainLen(struct val p[],int n)
{
   vector<pair<int,int> >v;
   
   for(int i = 0 ; i < n ; i++){
       v.push_back({p[i].first,p[i].second});
   }
   
   sort(v.begin(),v.end(),comp);
   
   int i = 0 , j = 1 , cnt = 1 , lv = v.size();
   
   while(j < lv){
       
       if(v[i].second < v[j].first){
           i = j;
           cnt++;
           j++;
       }
       else{
           j++;
       }
       
   }
   return cnt;
}



