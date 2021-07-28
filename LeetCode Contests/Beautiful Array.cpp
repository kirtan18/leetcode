https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3829/

////////////////////////////////////////////////////////////////////// T.C = O(N^2) || S.C = O(N)  /////////////////////////////////////////////////////////////////////////

  vector<int> beautifulArray(int n) {
        
        vector<int>res{1};
        if(n == 1)return res;
        
        while(res.size() < n){
            
            vector<int>temp;
            
            for(auto i : res){
                if(2*i <= n){
                    temp.push_back(2*i);
                }
            }
            
            for(auto i : res){
                if(2*i-1 <= n){
                    temp.push_back(2*i-1);
                }
            }
            
            res = temp;
        }
        return res;
    }


/////////////////////////////////////////////////////////////////////// T.C = O(NlogN) || S.C = O(N) ///////////////////////////////////////////////////////////////////

class Solution {
public:
    int partition(vector<int> &v, int start, int end, int mask)
    {
        int j = start;
        for(int i = start; i <= end; i++)
        {
            if((v[i] & mask) != 0)
            {
                swap(v[i], v[j]);
                j++;
            }
        }
        return j;
    }
    
    void sort(vector<int> & v, int start, int end, int mask)
    {
        if(start >= end) return;
        int mid = partition(v, start, end, mask);
        sort(v, start, mid - 1, mask << 1);
        sort(v, mid, end, mask << 1);
    }
    
    vector<int> beautifulArray(int N) {
        vector<int> ans;
        for(int i = 0; i < N; i++) ans.push_back(i + 1);
        sort(ans, 0, N - 1, 1);
        return ans;
    }
};

