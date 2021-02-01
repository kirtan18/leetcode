class Solution {
public:
    int xorOperation(int n, int start) {
        int arr[n];
        int Xor = 0;
        for(int i=0;i<n;i++){
            arr[i] = start + 2*i;
            Xor  ^= arr[i];
        }
        return Xor;
    }
};
