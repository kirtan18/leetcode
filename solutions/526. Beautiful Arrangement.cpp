class Solution {
public:
// time == O(k)  space == O(k)
    
 int res = 0;
void dfs(int* nums,int val){
    if(val == 0){
        res++;
        return;
    }
    for(int i = val; i>0;i--){
        swap(nums,i,val);
        
        if(nums[val] % val == 0 || val%nums[val] == 0){
            dfs(nums,val-1);
        }
        swap(nums,i,val);
      } 
   } 
    void swap(int*nums,int i ,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        
    }
    
 int countArrangement(int n) {
     
  int *nums = new int[n+1];    
     for(int i=1;i<=n;i++){
       nums[i] = i;
     }
     dfs(nums,n);
     return res;     
 }
