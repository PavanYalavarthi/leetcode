class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};
        for(int i = 0; i < s.size(); i++) freq[s[i] - 'a']++;
        int oddFreq = 0, evenFreq = 99;
        for(int j = 0, i; j< 26; j++) {
            i = freq[j];
            if (i != 0) {
                if (i & 1) oddFreq = max(oddFreq, i);
                else evenFreq = min(evenFreq, i);
            }
        }
        return oddFreq - evenFreq;
    }
};