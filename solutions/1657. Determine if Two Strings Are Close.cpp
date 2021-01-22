class Solution {
public:
​
    // time == O(n)  space == O(1)
    
bool closeStrings(string word1, string word2) {
    if(word1.size()!=word2.size()) return false;
​
    vector<int> counts1(26), counts2(26);
    for(auto i:word1)
        counts1[i-'a']++;
    for(auto i:word2)
        counts2[i-'a']++;
​
    for(int i=0;i<counts1.size();i++)
        if((counts1[i] and !counts2[i]) or (!counts1[i] and counts2[i])) 
            return false;
​
    sort(counts1.begin(),counts1.end());
    sort(counts2.begin(),counts2.end());
​
    return counts1 == counts2;
}
};
