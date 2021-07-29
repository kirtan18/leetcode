class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char>v,v1;
        int ans = 0;
        int f;
        if(x > y)f = 1;
        else f = 0;
        
        for(auto a : s){ 
            
            if(!v.empty()){
                if(f){
                    if(v.back() == 'a' && a == 'b'){
                        ans += x;
                        v.pop_back();
                    }else{
                        v.push_back(a);
                    }
                }
                else{
                    if(v.back() == 'b' && a == 'a'){
                        ans += y;
                        v.pop_back();
                    }else{
                        v.push_back(a);
                    }
                }
            }
            else{
                v.push_back(a);
            }
        }
        
        for(auto a : v){
            if(!v1.empty()){
                if(!f){
                    if(v1.back() == 'a' && a == 'b'){
                        ans += x;
                        v1.pop_back();
                    }
                    else v1.push_back(a);
                }
                else{
                    if(v1.back() == 'b' && a == 'a'){
                        ans += y;
                        v1.pop_back();
                    }
                    else v1.push_back(a);
                }
            }
            else{
                v1.push_back(a);
            }
        }
        
        return ans;
    }
};
