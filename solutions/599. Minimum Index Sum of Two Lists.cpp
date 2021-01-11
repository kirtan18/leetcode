 //////////////////// *********  explanation ************///////////////  
/*in this is  common  hoy  and  ena  index na  sum  jo   same  hoy  to  push  thay  and  jo  nana hoy  sum  to  push thyela  remove  thyi  jay  and  e  push thyi  jay p6i  enathi  moto koi push  nhi  thyi  ske */ 
​
class Solution {
public:
​
// time == O(l1 + l2)  space == O(l1 * x)
 vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector <string> ans;
        // Using hashmap or unordered_map because we also have to take care of index sum
        unordered_map <string, int> umap;
        int minSum = INT_MAX;
        
        // looping through the first list and pushing all values and index to hashmap
        for(int i=0; i<list1.size(); i++)
            umap[list1[i]] = i;
        
        // finding if both list have anything in common and have least index sum
        for(int i=0; i<list2.size(); i++)
        {
            // if element in common in lists
            if(umap.find(list2[i]) != umap.end())
            {
                // finding sum of index if element is common
                int sum = i + umap[list2[i]];
                // if we found new minimum, we clear the answer array as new minSum is present
                if(sum < minSum)
                    ans.clear();
                // if sum is same or less than minmum index, push it and assign minSum to sum
                if(sum <= minSum)
                {
                    ans.push_back(list2[i]);
                    minSum = sum;
