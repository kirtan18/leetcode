class Solution {
public:
    int numberOfMatches(int n) {
        int z =n;
        int k=0;
        
        for(int i=0;i<z;i++){
            while(z > 1){
                if(z % 2 == 0){
                    k  += z/2;
                    z  =  z/2;
                }
                else{
                    k  += z/2;
                    z = z/2 + 1;
                }
            }
        }
        return k;
    }
};
