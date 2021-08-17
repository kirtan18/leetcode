https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1#

//////////////////////////////////////////////////////DP approach//////////////////////////////////////////////////////
// T.C. : O(n^2) || TLE 
// S.C. : O(n)

class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int n = nums.size();
		    
		    if(n == 1) return 1;
		    int dp[n][2];
		    for(int i = 0 ;i < n ; i++){
		        dp[i][0] = dp[i][1] = 1;
		    }
		    
		    int ma = 0;
		    for(int i = 1; i < n ; i++){
		        for(int j = 0 ; j < i ; j++){
		            if(nums[i] > nums[j] && dp[i][0] < dp[j][1] +1){
		                dp[i][0] = dp[j][1] +1;
		            } 
		            else if(nums[i] < nums[j] && dp[i][1] < dp[j][0] +1){
		                dp[i][1] = dp[j][0] +1;
		            }
		        }
		        ma = max(ma , max(dp[i][0],dp[i][1]));
		    }
		    return ma;
		}
};


//////////////////////////////////////////////////////Linear approach//////////////////////////////////////////////////////
// T.C. : O(n)
// S.C. : O(1)

class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int n = nums.size();
		    
		    int ma = 1;
		    int mi = 1;
		    
		    for(int i = 1 ; i < n ; i++){
		        if(nums[i] > nums[i-1]){
		            ma = mi +1;
		        }
		        else if(nums[i] < nums[i-1]){
		            mi = ma +1;
		        }
		        else continue;
		    }
		    return max(ma,mi);
		}
};
