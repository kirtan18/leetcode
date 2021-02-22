class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
    sort(d.begin(), d.end(), [](const string& a, const string& b) {
        return (a.size() != b.size()) ? a.size() > b.size() : a < b;
    });
    for (string w : d) {
        int i = 0;
        for (int j = 0; j < s.size() && i < w.size();) {
            if (w[i] == s[j]) {
                i++;
                j++;
            }
            else
                j++;
        }
        if (i == w.size())
            return w;
    }
    return "";
}
};
​
