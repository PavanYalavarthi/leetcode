/*
Problem credits: https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/

You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.

Solution:
    Push index to priority queue and insert * at respective index to remove the index at constructing ans
*/
class Solution {
public:
    string clearStars(string s) {
        auto cmp = [&](int i, int j) {
            if (s[i] ==  s[j]) return i < j;
            return s[i] > s[j];
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                int index = pq.top();
                cout << index << endl;
                pq.pop();
                s[index] = '*';
            } else {
                pq.push(i);
            }
        }
        string ans;
        for(char c: s) {
            if (c != '*')
                ans += c;
        }
        return ans;

    }
};