class Solution {
public:
    // int & operation  only 1&1 then 1  other wise 0
    
    int hammingDistance(int x, int y) {
        int z = x^y;
        int count = 0;
        
        for(int i=0;i<32;i++){
            if(z&1){
                count++;
            }
            z = z>>1;
        }
        return count;
    }
};
/*
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y, count = 0;
        while(z){
            z &= (z-1);
            count ++;
        }
        return count;
    }
};
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y, count = 0;
        while(z){
            count += z&1;
            z>>=1;
        }
        return count;
    }
};
*/
