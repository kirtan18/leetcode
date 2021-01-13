class Solution {
public:
​
int numRescueBoats(vector<int>& people, int limit) {
        int numOfBoats = people.size(); // assume that initially we have boats = peoples
        
        sort(people.begin(), people.end()); // sorting to make easy check pairs using two pointers
        int f = 0; // start element
        int l = numOfBoats-1; // last element
        
        while(f < l) {
            if(people[f] + people[l] <= limit) { // if last and first elements sum <= limit 
                f++;         // move to next element for compare
                numOfBoats--; // then pair exist and boats required is 1 less
            }
            l--; // if not less then iterate back
        }
        return numOfBoats;
    }
};
