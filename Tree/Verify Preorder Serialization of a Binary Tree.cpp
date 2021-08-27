https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/


class Solution {
public:
    bool isValidSerialization(const string& preorder) {  
        // Capacity is number of leaf node needed in valid tree.
        // Initialy tree can have 1 node (root) either null or value.
        int capacity = 1;
        for(int i = 0; i <= preorder.size(); i++) {
            
            if (i < preorder.size() && preorder[i] != ',') continue;
            
            // We not continue means there is a value either node or leaf.
            // So we need 1 less leaf for above tree
            capacity--;
            
            // Number of leaf needed is negetive is not posible.
            if(capacity < 0)
                return false;
            
            // If we encounter another node than it has 2 more leafs so adding 2 in capacity.
            if(preorder[i-1] != '#')
                capacity += 2;
            cout << capacity << " ";
        }
        // Final capacity should be zero for valid tree.
        return capacity == 0; 
    }    
};
