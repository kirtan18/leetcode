class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>v;
        string temp = "";
        
        for(int i = 0 ; text[i] ; i++){
            if(text[i] == ' '){
                v.push_back(temp);
                temp = "";
            }else{
                temp += text[i];
            }
            
        }
        
        if(temp.size() > 0)v.push_back(temp);
        int vis[26]= {0};
        int cnt = 0;
        
        for(auto c : brokenLetters) vis[c-97] = 1;
        
        for(auto s : v){
            
            int fn = 1;
            for(auto c : s){
                if(vis[c-97] == 1){
                    fn = 0;
                    break;
                }
            }
            
            cnt += fn;
        }
        return cnt;
    }
};
