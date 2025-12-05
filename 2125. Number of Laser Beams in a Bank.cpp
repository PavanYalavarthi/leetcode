class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, prev = 0;
        for(string s : bank){
            int cnt = count(s);
            if(cnt == 0) continue;
            res += cnt * prev;
            prev = cnt;
        }
        return res;
    }
    int count(string s){
        int cnt = 0;
        for(char c : s)
            if( c == '1')
                cnt++;
        return cnt;
    }
};