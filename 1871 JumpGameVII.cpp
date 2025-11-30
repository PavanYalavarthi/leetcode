class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1') return false;
        int n = s.length();
        queue<int>q;
        q.push(0);
        int curr_max = 0;
        while(!q.empty()) {
            int i = q.front();
            if (i == n -1) return true;
            q.pop();
            for(int j = max(i+minJump , curr_max); j<=min(i+maxJump, n-1); j++) {
                if (s[j] == '0') q.push(j);
            }
            curr_max = min(1+maxJump+i, n);
        }
        return false;
    }
};