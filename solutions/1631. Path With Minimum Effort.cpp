class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
​
        int v[n+1][m+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v[i][j]=INT_MAX;
            }
        }
        v[0][0]=0;
        queue<pair<int,int> > q;
        q.push({0,0});
        int d[5]={0,-1,0,1,0};
        while(!q.empty())
        {
            pair<int,int> u =q.front();
            q.pop();
            for(int i =0;i<4;i++)
            {
                int x=u.first+d[i];
                int y=u.second +d[i+1];
​
                if(x<0||y<0||y>=m||x>=n) continue;
​
                if(v[x][y]<=v[ u.first ][ u.second ] ) continue;
​
                int p=max(v[ u.first ][ u.second ], abs(a[x][y]-a[ u.first ][ u.second ]));
                v[x][y]=min(p,v[x][y]);
                q.push({x,y});
            }
​
        }
        return v[n-1][m-1];
    }
    
    /*
    
    int vis[105][105];
    vector<pair<int,int>> dir = {{1,0} , {-1,0} , {0,-1} , {0,1}};
    void helper(int x , int y , int mid , vector<vector<int>>& heights){
        
        if(!vis[x][y]){
            vis[x][y] = 1;
            int n = heights.size();
            int m = heights[0].size();
            
            for(int i = 0 ; i < 4 ;i++){
                int X = x+dir[i].first;
                int Y = y+dir[i].second;
                
                if(X<0 || X>= n || Y<0 || Y>=m)
                    continue;
                
                if(abs(heights[x][y] - heights[X][Y]) <= mid)
                    helper(X,Y,mid,heights);
                
