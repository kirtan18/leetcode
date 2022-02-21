// https://leetcode.com/contest/weekly-contest-280/problems/minimum-operations-to-make-the-array-alternating/


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int freqEven[100001] = {0};
        int freqOdd[100001] = {0};
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(i % 2 == 0){
                freqEven[nums[i]]++;
            }
            else{
                freqOdd[nums[i]]++;
            }
            maxi = max(maxi,nums[i]);
        }
        
        
        int freqFirstEven = 0 , firstEven = 0;
        int freqSecondEven = 0, secondEven = 0;
        
        int freqFirstOdd = 0, firstOdd = 0;
        int freqSecondOdd = 0, secondOdd = 0;
        
        
        for(int i=1;i<=maxi;i++){
            
            if(freqEven[i] >= freqFirstEven){
                freqSecondEven = freqFirstEven;
                secondEven = firstEven;
                
                freqFirstEven = freqEven[i];
                firstEven = i;
            }
            
            else if(freqEven[i] > freqSecondEven){
                freqSecondEven = freqEven[i];
                secondEven = i;
            }
            
             if(freqOdd[i] >= freqFirstOdd){
                freqSecondOdd = freqFirstOdd;
                secondOdd = firstOdd;
                
                freqFirstOdd = freqOdd[i];
                firstOdd = i;
            }
            
            else if(freqOdd[i] > freqSecondOdd){
                freqSecondOdd = freqOdd[i];
                secondOdd = i;
            }
            
        }
        
        if(firstEven != firstOdd){
            return n - freqFirstEven - freqFirstOdd;
        }
        else 
            return min(n - freqFirstEven - freqSecondOdd,
                       n - freqFirstOdd - freqSecondEven);
        
        
    }
};
