https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/


///////////////////////////////////////////  TLE ///////////////////////////////////////



/////////////////////////////////////// Efiicient ///////////////////////////////////

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        k = k % n;
        
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};

////////////////////////////////////// Most Efficient ///////////////////////////////////////

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k%n == 0) return;
        int first = 0, middle = n-k%n, last = n;
        int next = middle;
        while(first != next) {
            swap (nums[first++], nums[next++]);
            if (next == last) next = middle;
            else if (first == middle) middle = next;
        }
    }
}; 
