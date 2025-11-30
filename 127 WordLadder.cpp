class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us(wordList.begin(), wordList.end());
        if (us.find(endWord) == us.end()) return 0;
        if (beginWord == endWord) return 1;
        queue<string> q;
        q.push(beginWord);
        us.erase(beginWord);
        int ans = 1;
        while(!q.empty()) {
            int sz = q.size();
            for(int i =0; i< sz; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) return ans;
                for (int i =0; i< word.length(); i++) {
                    char temp = word[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (us.find(word) != us.end()) {
                            q.push(word);
                            us.erase(word);
                        }
                    }
                    word[i] = temp;
                }
            }
            ans++;
        }
        return 0;
    }
};