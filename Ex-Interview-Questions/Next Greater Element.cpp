// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

vector<long long> nextLargerElement(vector<long long> arr, int n){
       stack<int> s;
       vector<long long>ans;
       int res[n];
       for (int i = n - 1; i >= 0; i--) {
        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
      }
      for(int i=0;i<n;i++){
          ans.push_back(res[i]);
      }
      return ans;
}



