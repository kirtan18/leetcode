class Solution {
public:
   
vector<int> shortestToChar(string S, char C) {
        vector<int> pos, dist;
        //storeing all positions of C
        for(int i=0; i<S.size(); i++){
            if(S[i] == C)
                pos.push_back(i);
        }
        
        //finding min distance
        for(int i=0; i<S.size(); i++){
            int mn=INT_MAX;
            for(int j=0; j<pos.size(); j++){
                mn = min(mn, abs(pos[j]-i));
            }
            dist.push_back(mn);
        }
        return dist;
    }
    
};
