class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> pos(26);
        priority_queue<char, vector<char>, greater<char>> pq;
        int index = 0;
        for(int i=0; i< s.size(); i++) {
            if (s[i] == '*') {
                index = pq.top() - 'a';
                s[pos[index].back()] = '*';
                pos[index].pop_back();
                if (pos[index].empty()) pq.pop();
            } else {
                index = s[i] - 'a';
                if (pos[index].empty()) pq.push(s[i]);
                pos[index].push_back(i);
            }
        }
        string res;
        for(char c: s) if(c != '*') res += c;
        return res;
    }
};