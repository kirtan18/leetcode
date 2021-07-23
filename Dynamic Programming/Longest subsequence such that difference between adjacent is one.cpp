https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1


///////////////////////////////////////////////////////  T.C = O(N^2) || S.C = O(N)  //////////////////////////////////////////////////////////


 int longestSubsequence(int N, int A[])
    {
        int dp[N];
        for(int i = 0 ; i < N ; i++)dp[i] = 1;
        
        for(int i = 1 ; i < N ; i++){
            for(int j = 0 ; j < i ; j++){
                if( abs(A[j] - A[i]) == 1 ){
                    dp[i] = max(dp[i] , dp[j]+1);
                }
            }
        }
        int mx = 0;
        for(int i = 0 ; i < N ; i++){
            mx = max(mx,dp[i]);
        }
        return mx;
    }


//////////////////////////////////////////////////// T.C = O(N) || S.C = O(N) /////////////////////////////////////////////////////////

 int longestSubsequence(int n, int a[])
    {
        unordered_map<int,int>mp;
        int ma = 0;
        for(int i = 0 ; i < n ; i++){
            
            int l = 0;
            if(mp[a[i]-1]) l = mp[a[i]-1];
            if(mp[a[i]+1] && mp[a[i]+1] > l) l = mp[a[i] + 1];
            
            mp[a[i]] = l + 1;
            ma = max(ma,mp[a[i]]);
        }
        return ma;
    }
