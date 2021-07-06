// https://leetcode.com/problems/peak-index-in-a-mountain-array/


//////////////////////////////////////////  Brute  || T.C = O(N) || S.C = O(1) ///////////////////////////////

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        for(int i = 0 ; i < arr.size() -1 ; i++){
            if(arr[i] > arr[i+1]){
                return i;
            }
        }
        return 0;
    }
};

///////////////////////////////////////////// Optimal  || T.C = O(logn) || S.C = O(1) //////////////////////////////////////////


 class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l = 0;
        int r = arr.size()-1;
        int mid;
        
        while( l <= r){
            mid = l + (r-l) / 2;
            
            if(arr[mid] < arr[mid+1]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }            
        }       
        return l;      
    }
};


/////////////////////////////////////////// One line  //////////////////////////////////


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
      return max_element(arr.begin(),arr.end())-arr.begin();
        
    }
};



