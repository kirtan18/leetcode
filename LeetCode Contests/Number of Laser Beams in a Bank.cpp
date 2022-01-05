// https://leetcode.com/contest/weekly-contest-274/problems/number-of-laser-beams-in-a-bank/

///////////////////////// Brute force ////////////////////////
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int first  = 0;
        int sec = 0;
        int main_ans = 0;
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(bank[i][j] == '1'){
                    cnt++;
                }
            }
            if(cnt == 0){
                continue;
            }
            else if(cnt > 0 && first == 0){
                first = cnt;
                cnt = 0;
                continue;
            }
            else{
                sec = cnt;
                int ans = first * sec;
                main_ans += ans;
                first = sec;
                sec = 0;
                cnt = 0;
            }
        }
        return main_ans;
    }
};

///////////// Optimal ///////////////////////////////

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0; 
        for (auto& row : bank) {
            int curr = count(row.begin(), row.end(), '1'); 
            if (curr) {
                ans += prev * curr; 
                prev = curr; 
            }
        }
        return ans; 
    }
};
