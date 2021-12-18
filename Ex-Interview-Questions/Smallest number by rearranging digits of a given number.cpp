// https://practice.geeksforgeeks.org/problems/smallest-number-by-rearranging-digits-of-a-given-number0820/1#

class Solution{
	public:
   	string minimum_Number(string s){
   	    int n = s.size();
   	    int num = stoi(s);
   	    int req = 0;
   	    if(num < 0){
   	        req = 1;
   	        int change = abs(num);
   	        s = to_string(change);
   	    }
   	    sort(s.begin(),s.end());
   	    int i = 0;
   	    while(s[i] == '0'){
   	        i++;
   	    }
   	    
   	    if(i == n)return s;
   	    swap(s[0],s[i]);
   	    if(req == 1){
   	        num = stoi(s);
   	        num = -(num);
   	        s = to_string(num);
   	    }
   	    return s;
   	}    
};
